///-------------------------------------------------------------------------
#ifndef DWARFELEPHANTRBSTRUCTURESA5THETAEQUALMU5TIMESMU12_H
#define DWARFELEPHANTRBSTRUCTURESA5THETAEQUALMU5TIMESMU12_H

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

struct DwarfElephantThetaA5EqualMu5TimesMu12 : RBTheta
{
  virtual Number evaluate (const RBParameters & _mu)
  {
    return (_mu.get_value("mu_5")*_mu.get_value("mu_12"));
  }
};

///-------------------------------------------------------------------------
#endif // DWARFELEPHANTRBSTRUCTURESA5THETAEQUALMU5TIMESMU12_H
