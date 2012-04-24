#include <stdlib.h>
#include <stdio.h>
#include "kar_helper.h"

big kar(big *list)
{
  big *q = malloc(101*sizeof(big));
  int i;
  for (i=0;i<100;i++)
  {
    q = Max_Heap_Insert(q,list[i],i);
  }

  int size = 100;
  while (size > 1)
  {
    q = Heap_Extract_Max(q,size);
    q = Heap_Extract_Max(q,size-1);
    big diff = q[size]-q[size-1];
    q = Max_Heap_Insert(q,diff,size-2);
    size--;
  }
  big res = q[1];
  free(q);
  return q[1];
}
