#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define big unsigned long long

big r(void);

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
  int i,j;
  FILE *fp = fopen("set.txt","w");
  for (j=0;j<n;j++)
  {
    big num = r();
    fprintf(fp,"%llu\n",num);
  }
  fclose(fp);
  return 0;
}


big r()
{
  big x = 0;
  int i;
  for (i=0;i<12;i++)
  {
    x*=10;
    x+=rand()%10;
    x*=10;
  }

  return x;
}
