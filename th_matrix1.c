#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
//#define MAX 2
void *mult(void* arg)
{
    int *data = (int *)arg;
    int k = 0, i = 0;
     
    int x = data[0];
    for (i = 1; i <= x; i++)
           k += data[i]*data[i+x];
     
    int *p = (int*)malloc(sizeof(int));
         *p = k;
    pthread_exit(p);
}
int main()
{int MAX;
 printf("the rows = the column = ");
 scanf("%d", &MAX);
    int r1=MAX,c1=MAX,r2=MAX,c2=MAX,i,j,k;
 int matA[10][10], matB[10][10];
 
    printf("\nEnter the elements of max1: \n");

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c1; ++j) {
         printf("Enter a%d%d: ", i + 1, j + 1);
         scanf("%d", &matA[i][j]);
        
}}
printf("\n");
 printf("\nEnter the elements of max2: \n");
   for (int i = 0; i < r2; ++i) {
      for (int j = 0; j < c2; ++j) {
         printf("Enter a%d%d: ", i + 1, j + 1);
         scanf("%d", &matB[i][j]);
    }}
    // Displaying 
    printf("\n matrix1\n");        
    for (i = 0; i < r1; i++){
        for(j = 0; j < c1; j++)
            printf("%d ",matA[i][j]);
        printf("\n");
    }
       printf("\n matrix2 \n");                
    for (i = 0; i < r2; i++){
        for(j = 0; j < c2; j++)
            printf("%d ",matB[i][j]);
        printf("\n");   
    }
     
     
    int max = r1*c2;
     
           
    pthread_t *threads;
    threads = (pthread_t*)malloc(max*sizeof(pthread_t));
     
    int count = 0;
    int* data = NULL;
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
               {
                
               //storing row and column elements in data
            data = (int *)malloc((20)*sizeof(int));
            data[0] = c1;
     
            for (int k = 0; k < c1; k++)
                data[k+1] = matA[i][k];
     
            for (int k = 0; k < r2; k++)
                data[k+c1+1] = matB[k][j];
              
             //creating threads
                pthread_create(&threads[count++], NULL,
                               mult, (void*)(data));
                 
                    }
     
    printf("RESULTANT MATRIX IS :- \n");
    for (int i = 0; i < max; i++)
    {
      void *k;
       
      //Joining all threads and collecting return value
      pthread_join(threads[i], &k);
            
           
          int *p = (int *)k;
      printf("%d ",*p);
      printf(" | ");
      if ((i + 1) % c2 == 0)
          printf("\n");
    }
  return 0;
}
