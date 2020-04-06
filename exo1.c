#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main (int args, char *argv[])
{
    #pragma omp parallel 
    {
        int NCPU, tid, NPR, NTHR;
        /* get the total number of CPUs/core available for OpenMp */
        NCPU = omp_get_num_procs();
        /* get the current thread ID in the parallel region */
        tid = omp_get_thread_num();
        /* get the total number of threads available in this parallel region*/
        NPR = omp_get_num_threads();
        /* get the total number of threads requested*/
        NTHR = omp_get_max_threads();
        /* only execute this on the master thread!*/
        if (tid == 0) {
            printf("%i : the total number of CPUs/core available = %i\n",tid,NCPU);
            printf("%i : get the total number of threads requested = %i\n",tid,NTHR);
            printf("%i : the total number of threads available in this parallel = %i\n",tid,NPR);
        } else {
            printf("%i : salem w alikom! je suis thread %i \n",tid,tid);
        }
    }
    return (0);
}