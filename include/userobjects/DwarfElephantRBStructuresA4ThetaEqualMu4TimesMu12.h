///-------------------------------------------------------------------------
#ifndef DWARFELEPHANTRBSTRUCTURESA4THETAEQUALMU4TIMESMU12_H
#define DWARFELEPHANTRBSTRUCTURESA4THETAEQUALMU4TIMESMU12_H

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

struct DwarfElephantThetaA4EqualMu4TimesMu12 : RBTheta
{
  virtual Number evaluate (const RBParameters & _mu)
  {
    return (_mu.get_value("mu_4")*_mu.get_value("mu_12"));
  }
};

///-------------------------------------------------------------------------
#endif // DWARFELEPHANTRBSTRUCTURESA4THETAEQUALMU4TIMESMU12_H
