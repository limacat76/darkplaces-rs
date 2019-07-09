// TODO Include Copyright notice
// todo code from view.c

#ifndef VIEW_H_
#define VIEW_H_

#include "cvar.h"
#include "matrixlib.h"

// Warnings/errors code:
// 0 - normal (everything all-right)
// 1 - world entity
// 2 - free entity
// 3 - null or non-precached model
// 4 - no tags with requested index
// 5 - runaway loop at attachment chain
extern cvar_t cl_bob;
extern cvar_t cl_bobcycle;
extern cvar_t cl_bobup;

extern cvar_t chase_active;

extern cvar_t cl_viewmodel_scale;

extern cvar_t v_kicktime;
extern cvar_t v_yshearing;

extern float v_dmg_time, v_dmg_roll, v_dmg_pitch;

void V_CalcRefdefUsing(const matrix4x4_t *entrendermatrix, const vec3_t clviewangles, bool teleported, bool clonground, bool clcmdjump, float clstatsviewheight, bool cldead, bool clintermission, const vec3_t clvelocity);



#endif

