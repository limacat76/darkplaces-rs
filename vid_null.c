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

#include "vid.h"
// END 010-quakedef.h.3

#include "console.h"
// END 005-quakedef.h.2

#include <signal.h>

int cl_available = false;

bool vid_supportrefreshrate = false;

void VID_Shutdown(void)
{
}

static void signal_handler(int sig)
{
	Con_Printf("Received signal %d, exiting...\n", sig);
	Sys_Quit(1);
}

static void InitSig(void)
{
#ifndef WIN32
	signal(SIGHUP, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGILL, signal_handler);
	signal(SIGTRAP, signal_handler);
	signal(SIGIOT, signal_handler);
	signal(SIGBUS, signal_handler);
	signal(SIGFPE, signal_handler);
	signal(SIGSEGV, signal_handler);
	signal(SIGTERM, signal_handler);
#endif
}

void VID_SetMouse (bool fullscreengrab, bool relative, bool hidecursor)
{
}

void VID_Finish (void)
{
}

void VID_Init(void)
{
	InitSig(); // trap evil signals
}

bool VID_InitMode(viddef_mode_t *mode)
{
	return false;
}

void *GL_GetProcAddress(const char *name)
{
	return NULL;
}

void Sys_SendKeyEvents(void)
{
}

void VID_BuildJoyState(vid_joystate_t *joystate)
{
}

void IN_Move(void)
{
}

vid_mode_t *VID_GetDesktopMode(void)
{
	return NULL;
}

size_t VID_ListModes(vid_mode_t *modes, size_t maxcount)
{
	return 0;
}
