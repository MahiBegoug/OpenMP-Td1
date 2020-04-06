#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define CHUNKSIZE 100
#define N 1000

void main() {

	int i , chunk ;
	double time_spent;
	clock_t begin,end;
	float tab1[N] , tab2[N] ,somme[N]; 
	chunk = CHUNKSIZE;

	for(i=0;i<N;i++) tab1[i] = tab2[i] = i* 1.0;

	begin = clock();

/// static avec chunk
	#pragma omp parallel shared(tab1,tab2,somme,chunk) private(i)
	{
		#pragma omp for schedule(static,chunk)
			for (i=0;i<N;i++)
				somme[i] = tab1[i] + tab2[i];
	}

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Static avec chunk : %f\n",time_spent);


/// static sans chunk
	begin = clock();

	#pragma omp parallel shared(tab1,tab2,somme) private(i)
	{
		#pragma omp for schedule(static)
			for (i=0;i<N;i++)
				somme[i] = tab1[i] + tab2[i];
	}

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Static sans chunk : %f\n",time_spent);
/// dynamic avec chunk
begin = clock();

	#pragma omp parallel shared(tab1,tab2,somme,chunk) private(i)
	{
		#pragma omp for schedule(dynamic,chunk)
			for (i=0;i<N;i++)
				somme[i] = tab1[i] + tab2[i];
	}

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Dynamic with chunk : %f\n",time_spent);

//// dynamic sans chunk
begin = clock();

	#pragma omp parallel shared(tab1,tab2,somme) private(i)
	{
		#pragma omp for schedule(dynamic)
			for (i=0;i<N;i++)
				somme[i] = tab1[i] + tab2[i];
	}

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Dynamic sans chunk : %f\n",time_spent);
}
