#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define big long long
int *gen_rand_alt(int n)
{
  srand(time(NULL));
  int *s = malloc(n*sizeof(int));
  int i;
  for (i=0;i<n;i++)
    s[i] = (rand() % n);

  return s;
}

big *preprocess(int *partitionnumbers, big *list)
{

  //list goes from 0 to 100, we want preprocess to as well, int goes from 0 to 100
  int i;
  int j;

  big *glued = malloc(100*sizeof(big));

  //initialize to zero
  for(i= 0; i < 100; i++)
  {
     glued[i] = 0;
  }

  for(i = 0; i < 100; i++)
  {
  
    j = partitionnumbers[i];
    glued[j] += list[i];

  }  

  return glued;

}


//Binary Heap Stuff

//Throughout, A is an array implementing our heap

//Returns the parent of A[i]
int Parent(int i){

return i/2; //we actually return floor i/2

}

//Returns left child
int Left(int i){

return 2*i;

}

//Returns right child
int Right(int i){

return 2*i+1; 

}

big *Max_Heapify(big *A, int i, int heapsize)
{

  int l = Left(i);
  int r = Right(i);
  int largest; 

  if(l <= heapsize && A[l] > A[i])
  {
    largest = l;
  }
  else{largest = i;}
  
  if( r <= heapsize && A[r] > A[largest] )
  {
    largest = r;
  }
  
  if(largest == i)
  {
  //if the biggest is in spot i, do nothing
  return A;
  }
  else
  {
  //exchange A[i] and A[largest]
  big temp = A[i];
  A[i] = A[largest];
  A[largest] = temp;

  Max_Heapify(A, largest, heapsize);

  }
}


big *Heap_Extract_Max(big *A, int heapsize)
{
 big max = A[1];

 A[1] = A[heapsize]; 
 //cheat and store the max value in the now empty last spot
 A[heapsize] = max;


 heapsize--;

 Max_Heapify(A, 1, heapsize);
 
 return A;
}
//remember to fucking manually decrement heapsize dude!


big *Heap_Increase_Key(big *A, int i, big key){

  A[i] = key;

  while(i > 1 && A[Parent(i)] < A[i])
  {
  //exchange A[i], and A[parent(i)]
  big temp = A[i];
  A[i] = A[Parent(i)];
  A[Parent(i)] = temp;
  
  i = Parent(i);
  }

 //return our modified heap
 return A;

} 


big *Max_Heap_Insert(big *A, big key, int heapsize)
{
//REMEMBER TO MANUALLY TOGGLE HEAPSIZES!!!!

//add in one last element to the heap with value key
A[heapsize+1] = key;

//let it float up the heap appropriately
return Heap_Increase_Key(A, heapsize+1, key);

}



