#include <stdlib.h>
#include "mathlib.h"
// END 010-quakedef.h.3

#include "console.h"
// END 005-quakedef.h.2

void fractalnoise(unsigned char *noise, int size, int startgrid)
{
	int x, y, g, g2, amplitude, min, max, size1 = size - 1, sizepower, gridpower;
	int *noisebuf;
#define n(x,y) noisebuf[((y)&size1)*size+((x)&size1)]

	for (sizepower = 0;(1 << sizepower) < size;sizepower++);
	if (size != (1 << sizepower))
	{
		Con_Printf("fractalnoise: size must be power of 2\n");
		return;
	}

	for (gridpower = 0;(1 << gridpower) < startgrid;gridpower++);
	if (startgrid != (1 << gridpower))
	{
		Con_Printf("fractalnoise: grid must be power of 2\n");
		return;
	}

	startgrid = bound(0, startgrid, size);

	amplitude = 0xFFFF; // this gets halved before use
	noisebuf = (int *)Mem_Alloc(tempmempool, size*size*sizeof(int));
	memset(noisebuf, 0, size*size*sizeof(int));

	for (g2 = startgrid;g2;g2 >>= 1)
	{
		// brownian motion (at every smaller level there is random behavior)
		amplitude >>= 1;
		for (y = 0;y < size;y += g2)
			for (x = 0;x < size;x += g2)
				n(x,y) += (rand()&amplitude);

		g = g2 >> 1;
		if (g)
		{
			// subdivide, diamond-square algorithm (really this has little to do with squares)
			// diamond
			for (y = 0;y < size;y += g2)
				for (x = 0;x < size;x += g2)
					n(x+g,y+g) = (n(x,y) + n(x+g2,y) + n(x,y+g2) + n(x+g2,y+g2)) >> 2;
			// square
			for (y = 0;y < size;y += g2)
				for (x = 0;x < size;x += g2)
				{
					n(x+g,y) = (n(x,y) + n(x+g2,y) + n(x+g,y-g) + n(x+g,y+g)) >> 2;
					n(x,y+g) = (n(x,y) + n(x,y+g2) + n(x-g,y+g) + n(x+g,y+g)) >> 2;
				}
		}
	}
	// find range of noise values
	min = max = 0;
	for (y = 0;y < size;y++)
		for (x = 0;x < size;x++)
		{
			if (n(x,y) < min) min = n(x,y);
			if (n(x,y) > max) max = n(x,y);
		}
	max -= min;
	max++;
	// normalize noise and copy to output
	for (y = 0;y < size;y++)
		for (x = 0;x < size;x++)
			*noise++ = (unsigned char) (((n(x,y) - min) * 256) / max);
	Mem_Free(noisebuf);
#undef n
}

// unnormalized, used for explosions mainly, does not allocate/free memory (hence the name quick)
void fractalnoisequick(unsigned char *noise, int size, int startgrid)
{
	int x, y, g, g2, amplitude, size1 = size - 1, sizepower, gridpower;
#define n(x,y) noise[((y)&size1)*size+((x)&size1)]

	for (sizepower = 0;(1 << sizepower) < size;sizepower++);
	if (size != (1 << sizepower))
	{
		Con_Printf("fractalnoise: size must be power of 2\n");
		return;
	}

	for (gridpower = 0;(1 << gridpower) < startgrid;gridpower++);
	if (startgrid != (1 << gridpower))
	{
		Con_Printf("fractalnoise: grid must be power of 2\n");
		return;
	}

	startgrid = bound(0, startgrid, size);

	amplitude = 255; // this gets halved before use
	memset(noise, 0, size*size);

	for (g2 = startgrid;g2;g2 >>= 1)
	{
		// brownian motion (at every smaller level there is random behavior)
		amplitude >>= 1;
		for (y = 0;y < size;y += g2)
			for (x = 0;x < size;x += g2)
				n(x,y) += (rand()&amplitude);

		g = g2 >> 1;
		if (g)
		{
			// subdivide, diamond-square algorithm (really this has little to do with squares)
			// diamond
			for (y = 0;y < size;y += g2)
				for (x = 0;x < size;x += g2)
					n(x+g,y+g) = (unsigned char) (((int) n(x,y) + (int) n(x+g2,y) + (int) n(x,y+g2) + (int) n(x+g2,y+g2)) >> 2);
			// square
			for (y = 0;y < size;y += g2)
				for (x = 0;x < size;x += g2)
				{
					n(x+g,y) = (unsigned char) (((int) n(x,y) + (int) n(x+g2,y) + (int) n(x+g,y-g) + (int) n(x+g,y+g)) >> 2);
					n(x,y+g) = (unsigned char) (((int) n(x,y) + (int) n(x,y+g2) + (int) n(x-g,y+g) + (int) n(x+g,y+g)) >> 2);
				}
		}
	}
#undef n
}

#define NOISE_SIZE 256
#define NOISE_MASK 255
float noise4f(float x, float y, float z, float w)
{
	int i;
	int index[4][2];
	float frac[4][2];
	float v[4];
	static float noisetable[NOISE_SIZE];
	static int r[NOISE_SIZE];
	// LordHavoc: this is inspired by code I saw in Quake3, however I think my
	// version is much cleaner and substantially faster as well
	//
	// the following changes were made:
	// 1. for the permutation indexing (r[] array in this code) I substituted
	//    the ^ operator (which never overflows) for the original addition and
	//    masking code, this should not have any effect on quality.
	// 2. removed the outermost randomization array lookup.
	//    (it really wasn't necessary, it's fine if X indexes the array
	//     directly without permutation indexing)
	// 3. reimplemented the blending using frac[] arrays rather than a macro.
	//    (the original macro read one parameter twice - not good)
	// 4. cleaned up the code by using 4 nested loops to make it read nicer
	//    (but then I unrolled it completely for speed, it still looks nicer).
	if (!noisetable[0])
	{
		// noisetable is a random-ish series of float values in +/- 1 range
		for (i = 0;i < NOISE_SIZE;i++)
			noisetable[i] = (rand() / (double)RAND_MAX) * 2 - 1;
		// r is a remapping table to make each dimension of the index have different indexing behavior
		for (i = 0;i < NOISE_SIZE;i++)
			r[i] = (int)(rand() * (double)NOISE_SIZE / ((double)RAND_MAX + 1)) & NOISE_MASK;
			// that & is only needed if RAND_MAX is > the range of double, which isn't the case on most platforms
	}
	frac[0][1] = x - floor(x);index[0][0] = ((int)floor(x)) & NOISE_MASK;
	frac[1][1] = y - floor(y);index[1][0] = ((int)floor(y)) & NOISE_MASK;
	frac[2][1] = z - floor(z);index[2][0] = ((int)floor(z)) & NOISE_MASK;
	frac[3][1] = w - floor(w);index[3][0] = ((int)floor(w)) & NOISE_MASK;
	for (i = 0;i < 4;i++)
		frac[i][0] = 1 - frac[i][1];
	for (i = 0;i < 4;i++)
		index[i][1] = (index[i][0] < NOISE_SIZE - 1) ? (index[i][0] + 1) : 0;
	// short version
	v[0] = frac[1][0] * (frac[0][0] * noisetable[r[r[r[index[3][0]] ^ index[2][0]] ^ index[1][0]] ^ index[0][0]] + frac[0][1] * noisetable[r[r[r[index[3][0]] ^ index[2][0]] ^ index[1][0]] ^ index[0][1]]) + frac[1][1] * (frac[0][0] * noisetable[r[r[r[index[3][0]] ^ index[2][0]] ^ index[1][1]] ^ index[0][0]] + frac[0][1] * noisetable[r[r[r[index[3][0]] ^ index[2][0]] ^ index[1][1]] ^ index[0][1]]);
	v[1] = frac[1][0] * (frac[0][0] * noisetable[r[r[r[index[3][0]] ^ index[2][1]] ^ index[1][0]] ^ index[0][0]] + frac[0][1] * noisetable[r[r[r[index[3][0]] ^ index[2][1]] ^ index[1][0]] ^ index[0][1]]) + frac[1][1] * (frac[0][0] * noisetable[r[r[r[index[3][0]] ^ index[2][1]] ^ index[1][1]] ^ index[0][0]] + frac[0][1] * noisetable[r[r[r[index[3][0]] ^ index[2][1]] ^ index[1][1]] ^ index[0][1]]);
	v[2] = frac[1][0] * (frac[0][0] * noisetable[r[r[r[index[3][1]] ^ index[2][0]] ^ index[1][0]] ^ index[0][0]] + frac[0][1] * noisetable[r[r[r[index[3][1]] ^ index[2][0]] ^ index[1][0]] ^ index[0][1]]) + frac[1][1] * (frac[0][0] * noisetable[r[r[r[index[3][1]] ^ index[2][0]] ^ index[1][1]] ^ index[0][0]] + frac[0][1] * noisetable[r[r[r[index[3][1]] ^ index[2][0]] ^ index[1][1]] ^ index[0][1]]);
	v[3] = frac[1][0] * (frac[0][0] * noisetable[r[r[r[index[3][1]] ^ index[2][1]] ^ index[1][0]] ^ index[0][0]] + frac[0][1] * noisetable[r[r[r[index[3][1]] ^ index[2][1]] ^ index[1][0]] ^ index[0][1]]) + frac[1][1] * (frac[0][0] * noisetable[r[r[r[index[3][1]] ^ index[2][1]] ^ index[1][1]] ^ index[0][0]] + frac[0][1] * noisetable[r[r[r[index[3][1]] ^ index[2][1]] ^ index[1][1]] ^ index[0][1]]);
	return frac[3][0] * (frac[2][0] * v[0] + frac[2][1] * v[1]) + frac[3][1] * (frac[2][0] * v[2] + frac[2][1] * v[3]);
}
