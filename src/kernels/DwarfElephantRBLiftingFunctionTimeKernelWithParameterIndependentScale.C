/**
 * This Kernel is implements the concept of the lifting function to avoid
 * problems caused by non-homogenous DirichletBC.
 */

 //---------------------------------INCLUDES-------------------------------
// MOOSE includes (DwarfElephant package)
#include "DwarfElephantRBLiftingFunctionTimeKernelWithParameterIndependentScale.h"

registerMooseObject("DwarfElephantApp", DwarfElephantRBLiftingFunctionTimeKernelWithParameterIndependentScale);

//----------------------------INPUT PARAMETERS-----------------------------
template<>
InputParameters validParams<DwarfElephantRBLiftingFunctionTimeKernelWithParameterIndependentScale>()
{
  InputParameters params = validParams<DwarfElephantRBKernel>();
  params.addClassDescription("The class implements a lifting function.");
  params.addRequiredParam<FunctionName>("lifting_function", "Name of the lifting function two account for the inhomogeneous Dirichlet boundary conditions.");
  params.addRequiredParam<Real>("scale", "Defines the value of the scaling parameter.");
  params.addParam<Real>("norm_value", 1.0, "Defines the normalization value.");

  return params;
}

//-------------------------------CONSTRUCTOR-------------------------------
DwarfElephantRBLiftingFunctionTimeKernelWithParameterIndependentScale::DwarfElephantRBLiftingFunctionTimeKernelWithParameterIndependentScale(const InputParameters & parameters) :
  DwarfElephantRBKernel(parameters),
  _lifting_function(&getFunction("lifting_function")),
  _scale(getParam<Real>("scale")),
  _norm_value(getParam<Real>("norm_value"))
{
}

//----------------------------------PDEs-----------------------------------
// Definition of the necessary PDE in the weak formulation

Real
DwarfElephantRBLiftingFunctionTimeKernelWithParameterIndependentScale::computeQpResidual()
{
  return  -(_scale/_norm_value)*_lifting_function->timeDerivative(_fe_problem.time(),_q_point[_qp])* _test[_i][_qp];
}

Real
DwarfElephantRBLiftingFunctionTimeKernelWithParameterIndependentScale::computeQpJacobian()
{
   return 0.0;
}
