///-------------------------------------------------------------------------
#ifndef DWARFELEPHANTRBSTRUCTURESA0THETAEQUALSCALARDIVIDEDBYMU0_H
#define DWARFELEPHANTRBSTRUCTURESA0THETAEQUALSCALARDIVIDEDBYMU0_H

///---------------------------------INCLUDES--------------------------------
// libMesh includes (RB package)
#include "libmesh/rb_theta.h"
#include "libmesh/rb_assembly_expansion.h"


// Forward Declarations
namespace libMesh
{
  class RBParameters;
  class RBTheta;
}

/**
 * Please take the name convention of this package for the mu object into
 * account to ensure a gernal useability of your class.
 */

struct DwarfElephantThetaA0EqualScalarDividedByMu0 : RBTheta
{
  virtual Number evaluate (const RBParameters & _mu)
  {
    return (1.0/_mu.get_value("mu_0"));
  }
};

///-------------------------------------------------------------------------
#endif // DWARFELEPHANTRBSTRUCTURESA0THETAEQUALSCALARDIVIDEDBYMU0_H
