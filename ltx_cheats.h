#ifndef LTX_CHEATS_H
#define LTX_CHEATS_H

extern qboolean noclip_anglehack;

extern cvar_t developer;
extern cvar_t developer_extra;
extern cvar_t developer_insane;
extern cvar_t developer_loadfile;
extern cvar_t developer_loading;

/// skill level for currently loaded level (in case the user changes the cvar while the level is running, this reflects the level actually in use)
extern int current_skill;

#endif