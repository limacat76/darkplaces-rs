/*
Copyright (C) 1996-1997 Id Software, Inc.
Copyright (C) 2003 Forest Hale
Copyright (C) 2019 Davide Inglima
Copyright (C) black, divverent, eihrul, knghtbrd, havoc, molivier, Nikoli, res, vortex

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

#ifndef LTX_CHEATS_H
#define LTX_CHEATS_H

#include "cvar.h"
// END 010-quakedef.h.3

extern bool noclip_anglehack;

extern cvar_t developer;
extern cvar_t developer_extra;
extern cvar_t developer_insane;
extern cvar_t developer_loadfile;
extern cvar_t developer_loading;

/// skill level for currently loaded level (in case the user changes the cvar while the level is running, this reflects the level actually in use)
extern int current_skill;

#endif