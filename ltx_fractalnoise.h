#ifndef LTX_FRACTALNOISE_H
#define LTX_FRACTALNOISE_H

void fractalnoise(unsigned char *noise, int size, int startgrid);
void fractalnoisequick(unsigned char *noise, int size, int startgrid);
float noise4f(float x, float y, float z, float w);

#endif