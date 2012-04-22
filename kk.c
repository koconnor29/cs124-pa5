#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helper.h"


#define max_iter 2

big compute_res(int *t, big* list);

int
main(int argc, char *argv[])
{
  srand(time(NULL));
  // filename stuff here

  int i,j;
  big *list = malloc(100*sizeof(big)); // list of numbers we are passed
  for (i=0;i<100;i++)
  {
    list[i] = r();
  }


  int flag = 0;
  int rep = 0;
  if (argc==4)
  {
    flag = atoi(argv[2]);
    rep = atoi(argv[3]);
  }

  big residue = (1<<30);
  residue*=residue;
  // repeated random
  if (flag == 0)
  {
    if (rep==0)
    {
      
      for (i=0;i<max_iter;i++)
      {
        int *t = gen_rand_std(100);
	big r = compute_res(t,list);
	if (r<residue)
	{
	  residue = r;
	}
	free(t);
      }
    }

  }
  free(list);
  printf("min residue: %llu\n",residue);
  return 0;
}

big compute_res(int *t,big *list)
{
  int i;
  long long sum = 0;
  for (i=0;i<100;i++)
  {
    sum+= t[i]*list[i];
  }

  if (sum<0)
    sum*=-1;

  return sum;
}
