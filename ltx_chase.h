#ifndef LTX_CHASE_H
#define LTX_CHASE_H

// chase
extern cvar_t chase_active;
extern cvar_t cl_viewmodel_scale;

void Chase_Init(void);
void Chase_Reset(void);
void Chase_Update(void);

#endif