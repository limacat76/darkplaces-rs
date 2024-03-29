#ifndef SV_DEMO_H
#define SV_DEMO_H

#include "crypto.h"
// END 010-quakedef.h.3

#include "netconn.h"
#include "progsvm.h"
#include "server.h"
// END 005-quakedef.h.2

void SV_StartDemoRecording(client_t *client, const char *filename, int forcetrack);
void SV_WriteDemoMessage(client_t *client, sizebuf_t *sendbuffer, bool clienttoserver);
void SV_StopDemoRecording(client_t *client);
void SV_WriteNetnameIntoDemo(client_t *client);

#endif
