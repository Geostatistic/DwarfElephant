 /**
  * The structures are defined for an elliptic PDE with the following restrictions:
  *  1. The number of thetas is equal to five (T5).
  *  2. The problem contains seven load vector (F7) and one output (O1).
  *
  * The structures defined are:
  * 1. Theta --> parameter-dependent part of the PDE
  * 2. RBThetaExpansion
  */

///-------------------------------------------------------------------------
#ifndef DWARFELEPHANTRBSTRUCTUREST5F7O1STEADYSTATE_H
#define DWARFELEPHANTRBSTRUCTUREST5F7O1STEADYSTATE_H

///---------------------------------INCLUDES--------------------------------
// libMesh includes (RB package)
#include "libmesh/rb_theta.h"
#include "libmesh/rb_assembly_expansion.h"

#include "DwarfElephantRBStructuresA00ThetaConstant.h"
#include "DwarfElephantRBStructuresA0ThetaEqualMu0.h"
#include "DwarfElephantRBStructuresA1ThetaEqualMu1.h"
#include "DwarfElephantRBStructuresA2ThetaEqualMu2.h"
#include "DwarfElephantRBStructuresA0ThetaEqualMu0TimesMu3.h"
#include "DwarfElephantRBStructuresA1ThetaEqualMu1TimesMu3.h"
#include "DwarfElephantRBStructuresA2ThetaEqualMu2TimesMu3.h"
#include "DwarfElephantRBStructuresA0ThetaEqualMu0TimesMu4.h"
#include "DwarfElephantRBStructuresA1ThetaEqualMu1TimesMu4.h"
#include "DwarfElephantRBStructuresA2ThetaEqualMu2TimesMu4.h"


// Forward Declarations
namespace libMesh
{
 // class RBParameters;
 // class RBTheta;
  class RBThetaExpansion;
}

///The structures are defined for an elliptic PDE with the following restrictions: 1. The number of thetas is equal to three (T3). 2. The problem contains four load vector (F4) and one output (O1).

/**
 * Attaches the stiffness matrix and the theta object to a structure of the
 * type RBThetatExpansion.
 *
 */

struct DwarfElephantRBT5F7O1SteadyStateExpansion : RBThetaExpansion
{
  DwarfElephantRBT5F7O1SteadyStateExpansion()
  {
    // Setting up the RBThetaExpansion object
    attach_A_theta(&_theta_a_0);
    attach_A_theta(&_theta_a_1);
    attach_A_theta(&_theta_a_2);

    attach_F_theta(&_rb_theta);
    attach_F_theta(&_theta_f_0);
    attach_F_theta(&_theta_f_1);
    attach_F_theta(&_theta_f_2);
    attach_F_theta(&_theta_f_3);
    attach_F_theta(&_theta_f_4);
    attach_F_theta(&_theta_f_5);

    attach_output_theta(&_rb_theta);
  }
  // Member Variables
  DwarfElephantThetaA0EqualMu0 _theta_a_0;
  DwarfElephantThetaA1EqualMu1 _theta_a_1;
  DwarfElephantThetaA2EqualMu2 _theta_a_2;
  DwarfElephantThetaA0EqualMu0TimesMu3 _theta_f_0;
  DwarfElephantThetaA1EqualMu1TimesMu3 _theta_f_1;
  DwarfElephantThetaA2EqualMu2TimesMu3 _theta_f_2;
  DwarfElephantThetaA0EqualMu0TimesMu4 _theta_f_3;
  DwarfElephantThetaA1EqualMu1TimesMu4 _theta_f_4;
  DwarfElephantThetaA2EqualMu2TimesMu4 _theta_f_5;
  RBTheta _rb_theta;         // Default RBTheta object, simply returns one.
};

///-------------------------------------------------------------------------
#endif // DWARFELEPHANTRBSTRUCTUREST5F7O1STEADYSTATE_H
