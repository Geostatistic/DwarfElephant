/**
 * This Kernel is required to use the RB method as it is provided by the
 * RB libMesh package. The RBTimeKernel inherits from the RBKernel class. It
 * overwrites the function computeJacobian because for the RB method the
 * mass matrix is needed separated in its subdomain contributions. In
 * addition it overwrites the function computeResidual.
 */

///-------------------------------------------------------------------------
#ifndef DWARFELEPHANTRBTIMEKERNEL_H
#define DWARFELEPHANTRBTIMEKERNEL_H

///---------------------------------INCLUDES--------------------------------
// MOOSE includes (DwarfElephant package)
#include "DwarfElephantRBKernel.h"

///This Kernel is required to use the RB method as it is provided by the RB libMesh package. The RBTimeKernel inherits from the RBKernel class. It overwrites the function computeJacobian because for the RB method the mass matrix is needed separated in its subdomain contributions. In addition it overwrites the function computeResidual.
class DwarfElephantRBTimeKernel;

///----------------------------INPUT PARAMETERS-----------------------------
template <>
InputParameters validParams<DwarfElephantRBTimeKernel>();

///All time kernels should inherit from this class
class DwarfElephantRBTimeKernel : public DwarfElephantRBKernel
{
//----------------------------------PUBLIC----------------------------------
public:
  DwarfElephantRBTimeKernel(const InputParameters & parameters);

  /*Methods*/
  virtual void computeResidual() override;
  virtual void computeJacobian() override;

// protected:
  /// Time derivative of u
  // const VariableValue & _u_dot;
  /// Derivative of u_dot with respect to u
  // const VariableValue & _du_dot_du;
};

///-------------------------------------------------------------------------
#endif // DWARFELEPHANTRBTIMEKERNEL_H
