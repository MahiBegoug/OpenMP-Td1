#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>



int main (int args, char *argv[])
{
    float a[1000], b[1000], c[1000];
    int i, chunk;

    for (i =0 ; i<1000; i++) a[i] = b [i] = i * 1.0;

    chunk = 100 ;

    double time_spent = 0.0;
    clock_t begin = clock();
    #pragma omp parallel shared(a,b,c,chunk) private(i)
    {
         #pragma omp for schedule(dynamic, chunk) nowait 
                for (i=0; i<1000; i++)  
                    c[i] = a[i] + b [i];
    }
   	clock_t end = clock();
    
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time elpased is %f seconds \n", time_spent);
    
    return (0);
}