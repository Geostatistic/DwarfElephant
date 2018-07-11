 /**
  * The structures are defined for an parabolic PDE with the following restrictions:
  *  1. The number of thetas is equal to three (T3).
  *  2. The problem contains one load vector (F1) and one output (O1).
  *
  * The structures defined are:
  * 1. Theta --> parameter-dependent part of the PDE
  * 2. RBThetaExpansion
  */
///-------------------------------------------------------------------------
#ifndef DWARFELEPHANTRBSTRUCTUREST6F1O1M1IC3TRANSIENT_H
#define DWARFELEPHANTRBSTRUCTUREST6F1O1M1IC3TRANSIENT_H

///---------------------------------INCLUDES--------------------------------
// libMesh includes (RB package)
#include "libmesh/transient_rb_theta_expansion.h"
#include "libmesh/transient_rb_assembly_expansion.h"

#include "DwarfElephantRBTransientThetaExpansion.h"
#include "DwarfElephantRBStructuresA00ThetaConstant.h"
#include "DwarfElephantRBStructuresA0ThetaEqualMu0.h"
#include "DwarfElephantRBStructuresA1ThetaEqualMu1.h"
#include "DwarfElephantRBStructuresA2ThetaEqualMu2.h"
#include "DwarfElephantRBStructuresA3ThetaEqualMu3.h"
#include "DwarfElephantRBStructuresA4ThetaEqualMu4.h"
#include "DwarfElephantRBStructuresA5ThetaEqualMu5.h"


// Forward Declarations
class DwarfElephantRBTransientThetaExpansion;

///----------------------------RBTHETAEXPANSION-----------------------------
/**
 * Attaches the stiffness matrix and the theta object to a structure of the
 * type RBThetatExpansion.
 *
 */

struct DwarfElephantRBT6F1O1M1IC3TransientExpansion : DwarfElephantRBTransientThetaExpansion
{
  DwarfElephantRBT6F1O1M1IC3TransientExpansion()
  {
    // Setting up the RBThetaExpansion object
    attach_M_theta(&_rb_theta);

    attach_A_theta(&_theta_a_0);
    attach_A_theta(&_theta_a_1);
    attach_A_theta(&_theta_a_2);

    attach_F_theta(&_rb_theta);

    attach_output_theta(&_rb_theta);

    attach_IC_theta(&_theta_a_3);
    attach_IC_theta(&_theta_a_4);
    attach_IC_theta(&_theta_a_5);

  }
  // Member Variables
  DwarfElephantThetaA00Constant _theta_a_00;
  DwarfElephantThetaA0EqualMu0 _theta_a_0;
  DwarfElephantThetaA1EqualMu1 _theta_a_1;
  DwarfElephantThetaA2EqualMu2 _theta_a_2;
  DwarfElephantThetaA3EqualMu3 _theta_a_3;
  DwarfElephantThetaA4EqualMu4 _theta_a_4;
  DwarfElephantThetaA5EqualMu5 _theta_a_5;
  RBTheta _rb_theta;         // Default RBTheta object, simply returns one.
};

///-------------------------------------------------------------------------
#endif // DWARFELEPHANTRBSTRUCTURESP1T3F1O1M1Transient_H
