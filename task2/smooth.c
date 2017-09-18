#include <stdlib.h>
#include <stdio.h>

void smooth(float* data, int sz_data, int sz_filter, float* output)
{
	int start;
	int end;

	if(sz_filter %2 == 1)
	{
		start = (sz_filter - 1)/2;
		end = (sz_filter - 1)/2;
	}
	else
	{
		start = sz_filter/2;
		end = start - 1;	
	}

	for(int i=start; i<(sz_data - end); i++)
	{
		for(int j=(0-start); j<=end; j++)
		{
			output[i] += data[i+j];
		}
		output[i] /= (float)sz_filter;
	}
}