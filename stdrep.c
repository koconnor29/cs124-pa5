#include <stdio.h>
#include <stdlib.h>


int *gen_rand_std(int n)
{
  //generate n (100) random plus or minus 1s
  srand(time(NULL));
  int *s = malloc(n*sizeof(int));
  int i;
  for (i=0;i<n;i++)
    s[i] = 2*(rand() % 2) - 1;

  return s;
}


int *neighbor(int* s)
{
 //choose two random indices between 0 and  100
 int i = rand() % 100;
 int j = rand() % 100;

 //switch s[i], s[j] with probability 1/2
 s[i]*= (2*(rand() % 2) - 1); 
 s[j]*= (2*(rand() % 2) - 1); 
 
 //output modified s
 return s;
}

