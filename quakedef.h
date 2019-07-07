/*
Copyright (C) 1996-1997 Id Software, Inc.

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
// quakedef.h -- primary header for client

#ifndef QUAKEDEF_H
#define QUAKEDEF_H

#include <sys/types.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <setjmp.h>

#include "ltx_dpfunctions.h"	// 17652
#include "qtypes.h"				// 17711
#include "ltx_engine.h"			// 26
#include "ltx_dpmemory.h"		// 17664
#include "ltx_gameconstants.h"  // 2848
#include "zone.h"				// 23
#include "fs.h"					// 7
#include "common.h"				// 21
#include "cvar.h"				// 404
#include "bspfile.h"			// 17638
#include "sys.h"				// 1495
#include "vid.h"				// 2054
#include "mathlib.h"			// 405
#include "r_textures.h"			// 17692
#include "crypto.h"				// 10590
#include "draw.h"				// 3236
#include "screen.h"				// 372
#include "netconn.h"			// 8805
#include "protocol.h"			// 17652 
// #include "cmd.h"				// 338

#if 1
#define QUAKEDEF_GAMENAME "005-quakedef.h.2.cmd.h"
#endif

#if 0
// vvv
#include "cmd.h"
// END 005-quakedef.h.2

#define QUAKEDEF_GAMENAME "Lichtopia-DarkPlaces-Quake"
#endif

#endif

