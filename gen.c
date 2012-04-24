#include<stdio.h>
#include<stdlib.h>
#include "gen_helper.h"

big *gen(int n)
{
  int i;
  big *list = malloc(n*sizeof(big));
  for (i=0;i<n;i++)
  {
    list[i] = r();
  }
  return list;
}
