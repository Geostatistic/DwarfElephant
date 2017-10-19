 ///-------------------------------------------------------------------------
// MOOSE includes (DwarfElephant package)
#include "DwarfElephantRBExecutioner.h"

template<>
InputParameters validParams<DwarfElephantRBExecutioner>()
{
  InputParameters params = validParams<Steady>();
  params.addParam<bool>("transient", false, "Determines whether the system is steady or transient.");
  params.addParam<bool>("offline_stage", true, "Determines whether the Offline stage will be calculated or not.");
  return params;
}

DwarfElephantRBExecutioner::DwarfElephantRBExecutioner(const InputParameters & params):
  Steady(params),
  _transient(getParam<bool>("transient")),
  _offline_stage(getParam<bool>("offline_stage"))
{
}

void
DwarfElephantRBExecutioner::execute()
{
  if (_app.isRecovering())
    return;

  preExecute();

  _problem.advanceState();

  // first step in any steady state solve is always 1 (preserving backwards compatibility)
  _time_step = 1;
  _time = _time_step;                 // need to keep _time in sync with _time_step to get correct output

#ifdef LIBMESH_ENABLE_AMR

  // Define the refinement loop
  unsigned int steps = _problem.adaptivity().getSteps();
  for (unsigned int r_step=0; r_step<=steps; r_step++)
  {
#endif //LIBMESH_ENABLE_AMR
    preSolve();
    _problem.timestepSetup();
    _problem.execute(EXEC_TIMESTEP_BEGIN);
    _problem.outputStep(EXEC_TIMESTEP_BEGIN);

    // Update warehouse active objects
    _problem.updateActiveObjects();

    if (_offline_stage)
      _problem.solve();
    postSolve();

//    if (!lastSolveConverged())
//    {
//      _console << "Aborting as solve did not converge\n";
//      break;
//    }
    _problem.onTimestepEnd();
    _problem.execute(EXEC_TIMESTEP_END);

    if(!_transient)
    {
      _problem.computeIndicators();
      _problem.computeMarkers();

      _problem.execute(EXEC_CUSTOM);

      _problem.outputStep(EXEC_TIMESTEP_END);
    }

#ifdef LIBMESH_ENABLE_AMR
    if (r_step != steps)
    {
      _problem.adaptMesh();
    }

    _time_step++;
    _time = _time_step;                 // need to keep _time in sync with _time_step to get correct output
  }
#endif

  postExecute();
}