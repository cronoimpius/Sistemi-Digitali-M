#include <stdio.h>
#include <stdlib.h>

void custom_func(const void *a1, const void *b1, const void *a2, const void *b2, void *result, const int h, const int w)
{
        float *c1 = (float *)calloc(h * w, sizeof(float));
	float *c2 = (float *)calloc(h * w, sizeof(float));
	int b1x, b1y, b2x, b2y;


	for (int i = 0; i < h; i++)
        	for (int j = 0; j < w; j++)
		{
			b1y = ((int*)b1)[i*w*2 + j*2 + 0];
			b1x = ((int*)b1)[i*w*2 + j*2 + 1];

			b2y = ((int*)b2)[i*w*2 + j*2 + 0];
                        b2x = ((int*)b2)[i*w*2 + j*2 + 1];

			c1[b1y*w + b1x] = ((float*)a1)[i*w + j];
			c2[b2y*w + b2x] = ((float*)a2)[i*w + j];

			((float*)result)[i*w + j] = c1[i*w + j] / c2[i*w + j];
		}
        free(c1);
        free(c2);
        return;
}
