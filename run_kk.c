#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kk_helper.h"
#include <math.h>

#define max_iter 25000

big compute_res(int *t, big* list);

big run_kk(big *list, int flag, int rep)
{
  int i;
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
  else  //hill climbing, simulated annealing
  {
    if (rep == 0)
    {
       //generate a single random collection of signs
       int *t = gen_rand_std(100);
       residue = compute_res(t, list);
       for (i = 0; i < max_iter; i++)
       {
         //create a neighbor of t and calculate its residue
         int *s =  neighbor(t);
	 big r = compute_res(t, list);

         //if it's lower, replace s with t and swtich the residues
	 if(r<residue)
	 {
           t = s;
	   residue = r;
	 }
         else if(flag == 2 && chance(r, residue, i) == 1) //for simulated annealing
	 {
           t = s;
	   //if we hit the required probability, via chance(), 
	   //replace t with s anyways
	 }
       }
    }
  }

  if (rep==1)
  {
    if (flag == 0)
    {
      int *t = gen_rand_alt(100);
      for (i=0;i<100;i++)
      {
        
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

int chance(int r, int residue, int i)
{
  //calculate our cutoff probability, 
  //blindly following the suggestion in the assignment
  float t = pow(10,10)*pow(0.8, floor(i/300)); //TBCOMpleted 
  float cutoff = exp((residue - r)/t);
  //calculate a random number between 0 and 1
  float x = (float) rand()/RAND_MAX;

  if(x < cutoff){ return 1;}
  else return 0;
}



