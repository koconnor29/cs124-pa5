#include<stdio.h>
#include<stdlib.h>
#include "gen_helper.h"

big *gen(big *list, int n)
{
  int i;
  for (i=0;i<n;i++)
  {
    list[i] = r();
  }
  return list;
}
