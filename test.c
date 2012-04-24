#include <stdio.h>
#include <stdlib.h>
#include "test_helper.h"

#define big long long

int
main()
{
  big *q = malloc(10*sizeof(big));
  int i;
  for (i=0;i<9;i++)
  {
    q = Max_Heap_Insert(q, 2*i+1,i);
  }


  for (i=0;i<9;i++)
  {
    q = Heap_Extract_Max(q,9-i);
    big x = q[9-i];
    printf("%d\n",x);
  }

  free(q);
  return 0;

}
