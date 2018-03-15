/**
 * In this class subclasses of the RBEvaluation and
 * RBConstruction class are introduced.
 *
 * DwarfElephantRBEvaluation: requires only the definition of the lower
 * coercivity constant. The value is here specified for a three layer
 * problem.
 *
 * DwarfElephantRBConstruction: In order to construct the RB System with the
 * DwarfElephantRBEvaluation subclass the method build_rb_evaluation needs to be
 * overriden.
 *
 * NOTE: ENSURE THAT THE CLASS IS USING THE CORRECT RBSTRUCTURES.
 */

///-------------------------------------------------------------------------
#ifndef DWARFELEPHANTRBCLASSESTRANSIENT_H
#define DWARFELEPHANTRBCLASSESTRANSIENT_H

///---------------------------------INCLUDES--------------------------------
//#if defined(LIBMESH_HAVE_SLEPC) && defined(LIBMESH_HAVE_GLPK)

// libMesh includes
#include "libmesh/sparse_matrix.h"
#include "libmesh/petsc_matrix.h"

// libMesh includes (RB package)
#include "libmesh/transient_rb_evaluation.h"
#include "libmesh/transient_rb_construction.h"

///-------------------------------------------------------------------------
// MOOSE includes (DwarfElephant package)
#include "DwarfElephantInitializeRBSystemTransient.h"

#include "DwarfElephantRBStructuresP1T1EqualF1O1Transient.h"
#include "DwarfElephantRBStructuresP1T2EqualF1O1Transient.h"
#include "DwarfElephantRBStructuresP1T3EqualF1O1Transient.h"
#include "DwarfElephantRBStructuresP1T3EqualF4O1Transient.h"
#include "DwarfElephantRBStructuresP1T4EqualF1O1Transient.h"
#include "DwarfElephantRBStructuresP1T5EqualF1O1Transient.h"
#include "DwarfElephantRBStructuresP1T5EqualF4O1Transient.h"

#include "FEProblemBase.h"

// Forward Declarations
namespace libMesh
{
  template <typename T> class SparseMatrix;
  template <typename T> class PetscMatrix;

  class EquationSystems;
  class TransientRBConstruction;
  class TransientRBEvaluation;
}

///-----------------------DWARFELEPHANTRBCONSTRUCTION-----------------------
class DwarfElephantRBConstructionTransient : public TransientRBConstruction
{

//---------------------------------PUBLIC-----------------------------------
public:

  // Constructor
  DwarfElephantRBConstructionTransient (EquationSystems & es,
                        const std::string & name_in,
                        const unsigned int number_in);

  // Destructor
  virtual ~DwarfElephantRBConstructionTransient () { }

  // Type of the system
  typedef DwarfElephantRBConstructionTransient _sys_type;

  // Type of the parent
  typedef TransientRBConstruction Parent;

  // Initialize data structure
  virtual void init_data() override;

  virtual Real truth_solve(int write_interval) libmesh_override;

  // virtual void print_info() override;
  //
  // virtual void initialize_truth() override;

  // void add_IC_to_RB_space();

  // void update_RB_initial_condition_all_N();

  // virtual void update_system() override;

  // virtual Real train_reduced_basis(const bool resize_rb_eval_data=true) override;

  unsigned int u_var;

};

///------------------------DWARFELEPHANTRBEVALUATION------------------------
class DwarfElephantRBEvaluationTransient : public TransientRBEvaluation
{

//---------------------------------PUBLIC-----------------------------------
public:
  DwarfElephantRBEvaluationTransient(const libMesh::Parallel::Communicator & comm, FEProblemBase & fe_problem);

  virtual Real get_stability_lower_bound();

  FEProblemBase & get_fe_problem() {return fe_problem;}

  FEProblemBase & fe_problem;
  DwarfElephantRBP1T3EqualF4O1TransientExpansion _rb_theta_expansion;
};
///-------------------------------------------------------------------------
#endif // DWARFELEPHANTRBCLASSESTRANSIENT_H
