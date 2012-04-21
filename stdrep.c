#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *gen_rand_std(int n);

int *gen_rand_std(int n)
{
  srand(time(NULL));
  int *s = malloc(n*sizeof(int));
  int i;
  for (i=0;i<n;i++)
    s[i] = 2*(rand() % 2) - 1;

  return s;
}

