#ifndef MOD_SKELTAL_ANIMATEVERTICES_SSE_H
#define MOD_SKELTAL_ANIMATEVERTICES_SSE_H

#ifdef SSE_POSSIBLE
void Mod_Skeletal_AnimateVertices_SSE(const dp_model_t * RESTRICT model, const frameblend_t * RESTRICT frameblend, const skeleton_t *skeleton, float * RESTRICT vertex3f, float * RESTRICT normal3f, float * RESTRICT svector3f, float * RESTRICT tvector3f);
#endif

#endif
