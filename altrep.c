#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int *gen_rand_alt(int n)
{
  srand(time(NULL));
  int *s = malloc(n*sizeof(int));
  int i;
  for (i=0;i<n;i++)
    s[i] = (rand() % n);

  return s;
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

int *Max_Heapify(int *A, int i, int heapsize)
{

  int l = Left(i);
  int r = Right(i);
  int largest; 

  if(l <= heapsize && A[l] > A[i])
  {
    largest = l;
  }
  else{largest = i;}
  
  if( r <= heapsize && A[r] > A[i] )
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
  int temp = A[i];
  A[i] = A[largest];
  A[largest] = temp;

  Max_Heapify(A, largest, heapsize);

  }
}


int *Heap_Extract_Max(int *A, int heapsize)
{
 int max = A[0];

 A[0] = A[heapsize - 1]; 
 //cheat and store the max value in the now empty last spot
 A[heapsize - 1] = max;


 heapsize--;

 Max_Heapify(A, 0, heapsize);
 
 return A;
}
//remember to fucking manually decrement heapsize dude!


int *Heap_Increase_Key(int *A, int i, int key){

  A[i] = key;

  while(i > 0 && A[Parent(i)] < A[i])
  {
  //exchange A[i], and A[parent(i)]
  int temp = A[i];
  A[i] = A[Parent(i)];
  A[Parent(i)] = temp;
  
  i = Parent(i);
  }

 //return our modified heap
 return A;

} 


int *Max_Heap_Insert(int *A, int key, int heapsize)
{
//REMEMBER TO MANUALLY TOGGLE HEAPSIZES!!!!

//add in one last element to the heap with value key
A[heapsize] = key;

//let it float up the heap appropriately
return Heap_Increase_Key(A, heapsize, key);

}



