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

#ifndef LTX_NETWORK_H
#define LTX_NETWORK_H

/// incremented every frame, never reset
extern int host_framecount;
/// not bounded in any way, changed at start of every frame, never reset
extern double realtime;
/// equal to Sys_DirtyTime() at the start of this host frame
extern double host_dirtytime;

void Host_InitCommands(void);
void Host_Main(void);
void Host_Shutdown(void);
void Host_StartVideo(void);
void Host_Error(const char *error, ...);
void Host_Quit_f(void);
void Host_ClientCommands(const char *fmt, ...);
void Host_ShutdownServer(void);
void Host_Reconnect_f(void);
void Host_NoOperation_f(void);
void Host_LockSession(void);
void Host_UnlockSession(void);

void Host_AbortCurrentFrame(void);

#endif