[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 10
  ny = 4
  nz = 2
  xmin = 0.0
  xmax = 3000
  ymin = 0.0
  ymax = 700
  zmin = 0.0
  zmax = 1000
[]

[MeshModifiers]
  [./subdomains]
    type = AssignElementSubdomainID
  #element_id = '0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 39 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 646 56 66 67 68 69 70 71 72 73 74 75 76 77 78 79'
  subdomain_ids = '0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1'
  [../]
[]

[Variables]
  [./temperature]
    order = FIRST
    family = LAGRANGE
  [../]
[]

#[AuxVariables]
#  [./loadVectorF0]
#    order = FIRST
#    family = LAGRANGE
#  [../]

#  [./stiffnessMatrixA0]
#    order = FIRST
#    family = LAGRANGE
#  [../]

#  [./stiffnessMatrixA1]
#    order = FIRST
#    family = LAGRANGE
#  [../]
# []

[Kernels]
  [./RBConduction_block0]
    type = Diffusion
    variable = temperature
   # diag_save_in = stiffnessMatrixA0
   # save_in = loadVectorF0
    block = 0
  [../]

  [./RBConduction_block1]
    type = Diffusion
    variable = temperature
   # diag_save_in = stiffnessMatrixA1
   # save_in = loadVectorF0
    block = 1
  [../]
 []

#[Materials]
#  [./shale_top]
#    type = ThetaObject
#    mu = '0.95 1.15'
#  [../]
#[]

[BCs]
  [./bottom]
    type = DirichletBC
    variable = temperature
    boundary = 'bottom'
    value = 31
  [../]
  [./top]
    type = DirichletBC
    variable = temperature
    boundary = 'top'
    value = 10
  [../]
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
[]

[UserObjects]
  [./prepareData_block0]
    type = DwarfElephantRBSystem
    system = nl0

    parameters_filename = 'smallRBTest.i'

    offline_stage = true
    online_stage = true
    store_basis_functions = true

    online_N = 20
    online_mu = '1.05 2.5 1.5'

   # block = 0

    file_name = block0
  [../]

  #[./prepareData_block1]
  #  type = DwarfElephantRBSystem
  #  system = nl0

  #  parameters_filename = 'smallRBTest.i'

  #  offline_stage = true
  #  online_stage = true
  #  store_basis_functions = true

  #  online_N = 20
  #  online_mu = '1.05 2.5 1.5'

  #  block = 1

  #  file_name = block1
  #[../]
[]

[Outputs]
  exodus = true
  xda = true
  xdr = true
  execute_on = 'timestep_end'
  #print_perf_log = true
[]

# ====================== Parameters for the RB approximation ======================

# Maximum number of basis functions that will be generated in the Offline-stage
Nmax = 20

# Name of the parameters
# Please name them mu_0, mu_1, ..., mu_n for the re-usability
parameter_names = 'mu_0 mu_1 mu_2'

# Define the minimum and maximum value of the Theta object
mu_0 = '0.95 1.15'
mu_1 = '2.2 2.8'
mu_2 = '0.95 1.15'

# Define the number of training sets for the Greedy-algorithm
n_training_samples = 10

# Optionally:
# Determine whether the training points are generated randomly or deterministically
deterministic_training = false

# Determine whether relative or absolute error bounds are used in the Greedy-algorithm
use_relative_bound_in_greedy = false

quiet_mode =  false
