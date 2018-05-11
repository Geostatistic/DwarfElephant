/* This UserObject is required to initialitze the RB system structure
 * and transfer for the transient case.
 */

///-------------------------------------------------------------------------
#ifndef DWARFELEPHANTINITIALIZERBSYSTEMTRANSIENT_H
#define DWARFELEPHANTINITIALIZERBSYSTEMTRANSIENT_H

///---------------------------------INCLUDES--------------------------------
//libMesh includes
#include "libmesh/equation_systems.h"
#include "libmesh/sparse_matrix.h"
#include "libmesh/petsc_matrix.h"
#include "libmesh/petsc_vector.h"

// MOOSE includes
#include "GeneralUserObject.h"
#include "DisplacedProblem.h"
#include "MooseMesh.h"

// MOOSE includes (DwarfElephant package)
#include "DwarfElephantSystem.h"
#include "DwarfElephantRBClassesTransient.h"
#include "DwarfElephantRBClassesSteadyState.h"
///-------------------------------------------------------------------------
// Forward Declarations
namespace libMesh
{
  class EquationSystems;
//  class RBConstruction;
  template <typename T> class SparseMatrix;
  template <typename T> class PetscMatrix;
  template <typename T> class PetscVector;
}

class MooseMesh;
class DwarfElephantSystem;
class DwarfElephantRBConstructionTransient;
class DwarfElephantRBConstructionSteadyState;
class DwarfElephantInitializeRBSystemTransient;

///----------------------------INPUT PARAMETERS-----------------------------
template<>
InputParameters validParams<DwarfElephantInitializeRBSystemTransient>();

///-------------------------------------------------------------------------
class DwarfElephantInitializeRBSystemTransient :
  public GeneralUserObject
{

//----------------------------------PUBLIC----------------------------------
  public:
    DwarfElephantInitializeRBSystemTransient(const InputParameters & params);

    /* Methods */

    void processParameters();

    // Initializes all required matrices and vectors for the RB solve.
    void initializeOfflineStage();

    // Initializes the RB System.
    // virtual void initialize() override;
    void initialize();

    // Method not used in this UserObject.
    // virtual void execute() override;
    void execute();

    // Method not used in this UserObject.
    // virtual void finalize() override;
    void finalize();

    std::vector<std::vector<NumericVector <Number> *> > getOutputs() const;

//--------------------------------PROTECTED---------------------------------
  protected:

    /* Attributes */
    bool _use_displaced;
    bool _skip_matrix_assembly_in_rb_system;
    bool _skip_vector_assembly_in_rb_system;
    bool _offline_stage;
    bool _deterministic_training;
    bool _quiet_mode;
    bool _normalize_rb_bound_in_greedy;
    bool _nonzero_initialization;

    int _max_truth_solves;
    unsigned int _n_training_samples;
    unsigned int _training_parameters_random_seed;
    unsigned int _N_max;
    unsigned int _n_time_steps;
    unsigned int _delta_N;
    unsigned int _n_outputs;
    unsigned int _qa;
    unsigned int _qm;
    unsigned int _qf;
    std::vector<unsigned int> _ql;

    Real _rel_training_tolerance;
    Real _abs_training_tolerance;
    Real _delta_time;
    Real _euler_theta;
    Real _POD_tol;
    std::vector<Real> _continuous_parameter_min_values;
    std::vector<Real> _continuous_parameter_max_values;
    std::vector<Real> _discrete_parameter_values_in;

    std::string _system_name;
//    std::string _parameters_filename;
    std::string _init_filename;
    std::vector<std::string> _continuous_parameters;
    std::vector<std::string> _discrete_parameters;
    std::map< std::string, std::vector<Real> > _discrete_parameter_values;

    EquationSystems & _es;
    MooseMesh * _mesh_ptr;
    TransientNonlinearImplicitSystem * _sys;
    DwarfElephantRBConstructionTransient * _rb_con_ptr;

    SparseMatrix <Number> * _inner_product_matrix;
    SparseMatrix <Number> * _L2_matrix;
    std::vector<SparseMatrix <Number> *> _jacobian_subdomain;
    std::vector<SparseMatrix <Number> *> _mass_matrix_subdomain;
    std::vector<NumericVector <Number> *> _residuals;
    std::vector<std::vector<NumericVector <Number> *> > _outputs;

    /*Friend Classes*/
    friend class DwarfElephantRBKernel;
    friend class DwarfElephantRBDiracKernel;
    friend class DwarfElephantRBTimeKernel;
    friend class DwarfElephantRBNodalBC;
    friend class DwarfElephantRBIntegratedBC;
    friend class DwarfElephantOfflineOnlineStageTransient;
    friend class DwarfElephantRBExecutioner;
    friend class DwarfElephantDakotaOutput;
};
///-------------------------------------------------------------------------
#endif // DWARFELEPHANTINITIALIZERBSYSTEMTRANSIENT_H
