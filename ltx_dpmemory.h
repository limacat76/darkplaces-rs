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

#ifndef LTX_DPMEMORY_H
#define LTX_DPMEMORY_H

// TODO LTX move this in lt_dpmemory.h
#ifdef DP_SMALLMEMORY
#define	MAX_INPUTLINE			1024
#define	CON_TEXTSIZE			16384
#define	CON_MAXLINES			256
#define	HIST_TEXTSIZE			2048
#define	HIST_MAXLINES			16
#define	MAX_ALIAS_NAME			32
#define	CMDBUFSIZE				131072
#define	MAX_ARGS				80

#define	NET_MAXMESSAGE			65536
#define	MAX_PACKETFRAGMENT		1024
#define	MAX_EDICTS				4096
#define	MAX_MODELS				1024
#define	MAX_SOUNDS				1024
#define	MAX_LIGHTSTYLES			64
#define	MAX_STYLESTRING			16
#define	MAX_SCOREBOARD			32
#define	MAX_SCOREBOARDNAME		128
#define	MAX_USERINFO_STRING		196
#define	MAX_SERVERINFO_STRING	512
#define	MAX_LOCALINFO_STRING	1 // not actually used by DP servers
#define	CL_MAX_USERCMDS			32
#define	CVAR_HASHSIZE			1024
#define	M_MAX_EDICTS			4096
#define	MAX_DEMOS				8
#define	MAX_DEMONAME			16
#define	MAX_SAVEGAMES			12
#define	SAVEGAME_COMMENT_LENGTH	39
#define	MAX_CLIENTNETWORKEYES	2
#define	MAX_LEVELNETWORKEYES	0 // no portal support
#define	MAX_OCCLUSION_QUERIES	256

#define CRYPTO_HOSTKEY_HASHSIZE 256
#define MAX_NETWM_ICON 1026 // one 32x32

#define	MAX_WATERPLANES			2
#define	MAX_CUBEMAPS			1024
#define	MAX_EXPLOSIONS			8
#define	MAX_DLIGHTS				16
#define	MAX_CACHED_PICS			1024 // this is 144 bytes each (or 152 on 64bit)
#define	CACHEPICHASHSIZE		256
#define	MAX_PARTICLEEFFECTNAME	256
#define	MAX_PARTICLEEFFECTINFO	1024
#define	MAX_PARTICLETEXTURES	256
#define	MAXCLVIDEOS				1
#define	MAX_DYNAMIC_TEXTURE_COUNT	2
#define	MAX_MAP_LEAFS			8192

#define	MAXTRACKS				256
#define	MAX_DYNAMIC_CHANNELS	64
#define	MAX_CHANNELS			260
#define	MODLIST_TOTALSIZE		32
#define	MAX_FAVORITESERVERS		32
#define	MAX_DECALSYSTEM_QUEUE	64
#define	PAINTBUFFER_SIZE		512
#define	MAX_BINDMAPS			8
#define	MAX_PARTICLES_INITIAL	8192
#define	MAX_PARTICLES			8192
#define	MAX_DECALS_INITIAL		1024
#define	MAX_DECALS				1024
#define	MAX_ENITIES_INITIAL		256
#define	MAX_STATICENTITIES		256
#define	MAX_EFFECTS				16
#define	MAX_BEAMS				16
#define	MAX_TEMPENTITIES		256
#define SERVERLIST_TOTALSIZE		1024
#define SERVERLIST_ANDMASKCOUNT		5
#define SERVERLIST_ORMASKCOUNT		5
#else
#define	MAX_INPUTLINE			16384 ///< maximum length of console commandline, QuakeC strings, and many other text processing buffers
#define	CON_TEXTSIZE			1048576 ///< max scrollback buffer characters in console
#define	CON_MAXLINES			16384 ///< max scrollback buffer lines in console
#define	HIST_TEXTSIZE			262144 ///< max command history buffer characters in console
#define	HIST_MAXLINES			4096 ///< max command history buffer lines in console
#define	MAX_ALIAS_NAME			32
#define	CMDBUFSIZE				655360 ///< maximum script size that can be loaded by the exec command (8192 in Quake)
#define	MAX_ARGS				80 ///< maximum number of parameters to a console command or alias

#define	NET_MAXMESSAGE			65536 ///< max reliable packet size (sent as multiple fragments of MAX_PACKETFRAGMENT)
#define	MAX_PACKETFRAGMENT		1024 ///< max length of packet fragment
#define	MAX_EDICTS				32768 ///< max number of objects in game world at once (32768 protocol limit)
#define	MAX_MODELS				8192 ///< max number of models loaded at once (including during level transitions)
#define	MAX_SOUNDS				4096 ///< max number of sounds loaded at once
#define	MAX_LIGHTSTYLES			256 ///< max flickering light styles in level (note: affects savegame format)
#define	MAX_STYLESTRING			64 ///< max length of flicker pattern for light style
#define	MAX_SCOREBOARD			255 ///< max number of players in game at once (255 protocol limit)
#define	MAX_SCOREBOARDNAME		128 ///< max length of player name in game
#define	MAX_USERINFO_STRING		1280 ///< max length of infostring for PROTOCOL_QUAKEWORLD (196 in QuakeWorld)
#define	MAX_SERVERINFO_STRING	1280 ///< max length of server infostring for PROTOCOL_QUAKEWORLD (512 in QuakeWorld)
#define	MAX_LOCALINFO_STRING	32768 ///< max length of server-local infostring for PROTOCOL_QUAKEWORLD (32768 in QuakeWorld)
#define	CL_MAX_USERCMDS			128 ///< max number of predicted input packets in queue
#define	CVAR_HASHSIZE			65536 ///< number of hash buckets for accelerating cvar name lookups
#define	M_MAX_EDICTS			32768 ///< max objects in menu vm
#define	MAX_DEMOS				8 ///< max demos provided to demos command
#define	MAX_DEMONAME			16 ///< max demo name length for demos command
#define	MAX_SAVEGAMES			12 ///< max savegames listed in savegame menu
#define	SAVEGAME_COMMENT_LENGTH	39 ///< max comment length of savegame in menu
#define	MAX_CLIENTNETWORKEYES	16 ///< max number of locations that can be added to pvs when culling network entities (must be at least 2 for prediction)
#define	MAX_LEVELNETWORKEYES	512 ///< max number of locations that can be added to pvs when culling network entities (must be at least 2 for prediction)
#define	MAX_OCCLUSION_QUERIES	4096 ///< max number of GL_ARB_occlusion_query objects that can be used in one frame

#define CRYPTO_HOSTKEY_HASHSIZE 8192 ///< number of hash buckets for accelerating host key lookups
#define MAX_NETWM_ICON 352822 // 16x16, 22x22, 24x24, 32x32, 48x48, 64x64, 128x128, 256x256, 512x512

#define	MAX_WATERPLANES			16 ///< max number of water planes visible (each one causes additional view renders)
#define	MAX_CUBEMAPS			1024 ///< max number of cubemap textures loaded for light filters
#define	MAX_EXPLOSIONS			64 ///< max number of explosion shell effects active at once (not particle related)
#define	MAX_DLIGHTS				256 ///< max number of dynamic lights (rocket flashes, etc) in scene at once
#define	MAX_CACHED_PICS			1024 ///< max number of 2D pics loaded at once
#define	CACHEPICHASHSIZE		256 ///< number of hash buckets for accelerating 2D pic name lookups
#define	MAX_PARTICLEEFFECTNAME	4096 ///< maximum number of unique names of particle effects (for particleeffectnum)
#define	MAX_PARTICLEEFFECTINFO	8192 ///< maximum number of unique particle effects (each name may associate with several of these)
#define	MAX_PARTICLETEXTURES	256 ///< maximum number of unique particle textures in the particle font
#define	MAXCLVIDEOS				65 ///< maximum number of video streams being played back at once (1 is reserved for the playvideo command)
#define	MAX_DYNAMIC_TEXTURE_COUNT	64 ///< maximum number of dynamic textures (web browsers, playvideo, etc)
#define	MAX_MAP_LEAFS			65536 ///< maximum number of BSP leafs in world (8192 in Quake)

#define	MAXTRACKS				256 ///< max CD track index
// 0 to NUM_AMBIENTS - 1 = water, etc
// NUM_AMBIENTS to NUM_AMBIENTS + MAX_DYNAMIC_CHANNELS - 1 = normal entity sounds
// NUM_AMBIENTS + MAX_DYNAMIC_CHANNELS to total_channels = static sounds
#define	MAX_DYNAMIC_CHANNELS	512
#define	MAX_CHANNELS			(8192 + 4)
#define	MODLIST_TOTALSIZE		256
#define	MAX_FAVORITESERVERS		256
#define	MAX_DECALSYSTEM_QUEUE	1024
#define	PAINTBUFFER_SIZE		2048
#define	MAX_BINDMAPS			8
#define	MAX_PARTICLES_INITIAL	8192 ///< initial allocation for cl.particles
#define	MAX_PARTICLES			1048576 ///< upper limit on cl.particles size
#define	MAX_DECALS_INITIAL		8192 ///< initial allocation for cl.decals
#define	MAX_DECALS				1048576 ///< upper limit on cl.decals size
#define	MAX_ENITIES_INITIAL		256 ///< initial size of cl.entities
#define	MAX_STATICENTITIES		1024 ///< limit on size of cl.static_entities
#define	MAX_EFFECTS				256 ///< limit on size of cl.effects
#define	MAX_BEAMS				256 ///< limit on size of cl.beams
#define	MAX_TEMPENTITIES		4096 ///< max number of temporary models visible per frame (certain sprite effects, certain types of CSQC entities also use this)
#define SERVERLIST_TOTALSIZE		2048 ///< max servers in the server list
#define SERVERLIST_ANDMASKCOUNT		16 ///< max items in server list AND mask
#define SERVERLIST_ORMASKCOUNT		16 ///< max items in server list OR mask
#endif


#define CMD_TOKENIZELENGTH (MAX_INPUTLINE + MAX_ARGS) ///< maximum tokenizable commandline length (counting trailing 0)

// limaCAT: hey guys, seriously?
#define	MAX_QPATH		128			///< max length of a quake game pathname
#ifdef PATH_MAX
#define	MAX_OSPATH		PATH_MAX
#elif MAX_PATH
#define	MAX_OSPATH		MAX_PATH
#else
#define	MAX_OSPATH		1024		///< max length of a filesystem pathname
#endif



#endif
