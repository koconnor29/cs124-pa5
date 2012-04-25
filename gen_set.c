#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define big long long
big *gen(big *list, int n);

int
main(int argc, char *argv[])
{
  srand(time(NULL));
  if (argc!=2)
  {
    printf("Usage: ./gen_set (size of set)\n");
    return 1;
  }

  int n = atoi(argv[1]);
  int j;
  big *list = malloc(100*sizeof(big));
  gen(list, n);
  FILE *fp = fopen("set.txt","w");
  for (j=0;j<n;j++)
    fprintf(fp,"%llu\n",list[j]);
 
  free(list);
  fclose(fp);
  return 0;
}
