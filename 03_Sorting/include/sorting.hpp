
#ifndef sorting_hpp
#define sorting_hpp

void insertion_sort(int * A, int N);

int Partition(int * array, int begin, int end, int pivot);

void Quick_Sort(int* array, int begin, int end);

void Quick_Sort_Best(int* array, int begin, int end);

void Counting_Sort(int * A, int * B,  int sizeA);

void Counting_Sort_Aux(int * array, int size, int place);

void Radix_Sort(int * array, int size);

Node* Bubble_Sort( Node * first);

void Bucket_Sort(double *array, int n);

void heap_sort(int * array, int size);

#endif /* sorting_hpp */
