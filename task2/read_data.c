#include <stdlib.h>
#include <stdio.h>

int get_data(FILE* datafile, float* data, int sz_data)
{
	int i=0;

	char line[32];

	while( (fgets(line, sizeof line, datafile) !=NULL) && (i < sz_data) )
	{
		data[i] = atof(line);
		//printf("%f\n", data[i]);
		i++;
	}

	return i;
}