#ifndef MOD_SKELETAL_ANIMATEVERTICES_GENERIC_H
#define MOD_H

#include "client.h"
// END 005-quakedef.h.2

void Mod_Skeletal_AnimateVertices_Generic(const dp_model_t * RESTRICT model, const frameblend_t * RESTRICT frameblend, const skeleton_t *skeleton, float * RESTRICT vertex3f, float * RESTRICT normal3f, float * RESTRICT svector3f, float * RESTRICT tvector3f);

#endif
