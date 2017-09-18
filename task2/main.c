#include <stdlib.h>
#include <stdio.h>
#include <read_data.h>
#include <smooth.h>

#define MAX_LINES 256
#define SZ_FILTER 15

int main(void)
{
	FILE* inputFile;
	inputFile = fopen("datafile.dat", "r");

	if(inputFile==NULL)
	{
		printf("file open failed");
		return 1;
	}

	float inputData[MAX_LINES];
	
	int sz_data = get_data(inputFile, inputData, MAX_LINES);
	printf("Read %i lines\n\n",sz_data);

	fclose(inputFile);



	float outputData[sz_data - SZ_FILTER +1];

	smooth(inputData, sz_data, SZ_FILTER, outputData);

	for(int i=0; i < sizeof outputData; i++)
	{
		printf("%f\n", outputData[i]);
	}

	return 0;
}