#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define big long long

big r()
{
  big x = 0;
  int i;
  for (i=0;i<12;i++)
  {
    x*=10;
    x+=rand()%10;
  }

  return x;
}

/*
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
    fprintf(fp,"%ll\n",num);
  }
  fclose(fp);
  return 0;
}
*/

