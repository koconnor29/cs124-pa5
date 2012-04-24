#include <stdio.h>
#include <stdlib.h>

#define big long long


int *gen_rand_std(int n)
{
  //generate n (100) random plus or minus 1s
  int *s = malloc(n*sizeof(int));
  int i;
  for (i=0;i<n;i++)
    s[i] = 2*(rand() % 2) - 1;

  return s;
}


int *neighbor(int* s)
{
 big *new = malloc(100*sizeof(big));
 
 //fill in new with s
 int i;
 for(i = 0; i < 100; i++){
   new[i] = s[i];
 }

 //choose two random indices between 0 and  100
 int i = rand() % 100;
 int j = rand() % 100;

 //switch s[i], s[j] with probability 1/2
 new[i]*= (2*(rand() % 2) - 1); 
 new[j]*= (2*(rand() % 2) - 1); 
 
 //output modified s
 return new;
}

