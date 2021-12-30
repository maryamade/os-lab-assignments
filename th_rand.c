#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_THREADS 5
void *ArraySum(void *arg)
{
   int array[NUM_THREADS];
    int id = (int)arg;
    int partial_sum = 0;
    int begin = id * (NUM_THREADS + 1);
    int end = id * (NUM_THREADS + 1) + NUM_THREADS;
    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++)
    {
        array[i] = 0;
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        array[i] = rand() % 10 ;
        partial_sum += array[i];
 
   }
/*    for(int i = begin; i <= end; i++)
    {
        partial_sum += array[i];
    }
  */  // Exiting current thread
    pthread_exit((void *)partial_sum);
}
int main(int argc, char *argv[])
{
   int rc;
    int t;
    int arraySum = 0;
    void *retvalue;
    // Creating thread array
    pthread_t threads[NUM_THREADS];

    // Iterating over each thread
    for(t = 0; t < NUM_THREADS; t++)
    {
        rc = pthread_create(&threads[t], NULL, ArraySum, (void *)t);
        if(rc)
        {
            printf(" Error; return code from pthread_create() is %d \n", rc);
            exit(-1);
        }
    }
    for (t = 0; t < NUM_THREADS; t++)
    {
         pthread_join(threads[t], &retvalue);
         arraySum += (int)retvalue;
    }
    printf("\nArray Sum: %d \n", arraySum);
    pthread_exit(NULL);
}
