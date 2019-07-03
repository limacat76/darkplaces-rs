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
void Host_Error(const char *error, ...) DP_FUNC_PRINTF(1) DP_FUNC_NORETURN;
void Host_Quit_f(void);
void Host_ClientCommands(const char *fmt, ...) DP_FUNC_PRINTF(1);
void Host_ShutdownServer(void);
void Host_Reconnect_f(void);
void Host_NoOperation_f(void);
void Host_LockSession(void);
void Host_UnlockSession(void);

void Host_AbortCurrentFrame(void);

#endif