#ifndef Select_hpp
#define Select_hpp


void insertion_sort(int * array, int start, int size);

int partition(int * array, int low, int high, int pivot);

int select_pivot(int * array, int low, int high);

int select_aux(int * array, int low, int high, int i);

int selection(int * A, int i, int N);

#endif /* Select_hpp */

