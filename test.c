#include <stdio.h>
#include <stdlib.h>
#include "test_helper.h"

int
main()
{
  int *q = malloc(10*sizeof(int));
  int i;
  for (i=0;i<9;i++)
    Max_Heap_Insert(q,2*i+1,i);

  for (i=0;i<9;i++)
  {
    q = Heap_Extract_Max(q,9-i);
    int x = q[9-i];
    printf("%d\n",x);
  }

  free(q);
  return 0;

}
