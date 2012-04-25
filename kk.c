#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define big long long

big run_kk(big* list,int flag, int rep);
big *gen(big *list, int n);
big kar(big *list);

int
main(int argc, char *argv[])
{
  srand(time(NULL));
  int i,j;

  big result = 0;

  if (argc!=2 && argc!=3 && argc!=4)
  {
    printf("Usage: ./kk filename [mode] [rep]");
    return 1;
  }
  
  int flag = 0;
  int rep = 0;
  big *list;
  if (argc==2)
  {
    list = malloc(100*sizeof(big));
    char *filename = argv[1];
    FILE *fp = fopen(filename,"r");
    for (i=0;i<100;i++)
    {
      fscanf(fp,"%llu\n",&list[i]);
    }

    result = kar(list);
    printf("Residue: %llu\n",result);
  }

  if (argc==3)
  {
    big res[6];
    for (i=0;i<6;i++)
      res[i] = 0;

    big kres = 0;
    list = malloc(100*sizeof(big));
    for(i=0;i<50;i++)
    {
      gen(list,100);
      for (flag=0;flag<3;flag++)
      {
        for (rep=0;rep<2;rep++)
	{
	  res[3*rep+flag]+=run_kk(list,flag,rep);
	}
      }
      kres += kar(list);
    }
    for (i=0;i<6;i++)
      res[i] = res[i]/50;

    kres = kres/50;

    printf("Rep: std, Mode: rep. rand. --> avg. result: %llu\n",res[0]);
    printf("Rep: std, Mode: hill climb --> avg. result: %llu\n",res[1]);
    printf("Rep: std, Mode: sim. anneal --> avg. result: %llu\n",res[2]);
    printf("Rep: alt, Mode: rep. rand. --> avg. result: %llu\n",res[3]);
    printf("Rep: alt, Mode: hill climb --> avg. result: %llu\n",res[4]);
    printf("Rep: alt, Mode: sim. anneal --> avg. result: %llu\n",res[5]);
    printf("Regular Karm-Karp --> avg. result: %llu\n", kres);
  }


  if (argc==4)
  {
    list = malloc(100*sizeof(big));
    flag = atoi(argv[2]);
    rep = atoi(argv[3]);
    if (rep == 2)
    {
      gen(list,100);
      result=kar(list);
    }
    for (i=0;i<50;i++)
    {
      gen(list,100);
      result += run_kk(list,flag,rep);
    }
    result = result/50; 
    printf("Avg. Residue: %llu\n",result);
  }


  free(list);
  return 0;

}
