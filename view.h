/*
Copyright (C) 1996-1997 Id Software, Inc.
Copyright (C) 2003-2019 Forest Hale & Contributors
Copyright (C) 2019 Davide Inglima

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
/*
Quake is a trademark of Id Software, Inc., (c) 1996 Id Software, Inc. All
rights reserved.
*/

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

// TODO Move back to screen or sbar.c
extern cvar_t crosshair;

extern cvar_t v_kicktime;
extern cvar_t v_yshearing;

extern float v_dmg_time, v_dmg_roll, v_dmg_pitch;

void V_Init(void);

void V_CalcRefdef(void);
void V_CalcRefdefUsing(const matrix4x4_t *entrendermatrix, const vec3_t clviewangles, bool teleported, bool clonground, bool clcmdjump, float clstatsviewheight, bool cldead, bool clintermission, const vec3_t clvelocity);
float V_CalcRoll(const vec3_t angles, const vec3_t velocity);
void V_CalcViewBlend(void);

void V_StartPitchDrift(void);
void V_StopPitchDrift(void);

void V_DriftPitch(void);
void V_FadeViewFlashs(void);

void V_ParseDamage(void);

#endif

