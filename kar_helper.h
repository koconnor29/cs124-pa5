#define big long long

int Parent(int i);
int Left(int i);
int Right(int i);
big *Max_Heapify(big *A, int i, int heapsize);
big *Heap_Extract_Max(big *A, int heapsize);
big *Heap_Increase_Key(big *A, int i, big key);
big *Max_Heap_Insert(big *A, big key, int heapsize);
