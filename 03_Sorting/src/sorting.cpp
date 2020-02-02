#include <iostream>
#include <cmath>
#include "../include/array_utilities.hpp"
#include "../include/sorting.hpp"
#include "../include/heap.hpp"

/* INSERTION SORT */

void insertion_sort(int * A, int N){
    for(int i = 1; i < N ; i++){
        int j = i;
        while(j>0 && A[j]<A[j-1]){
            swap(A, j-1,j);
            j = j-1;
        }
    }
}

/*  QUICK SORT */

int Partition(int * array, int begin, int end, int pivot){
    swap(array, begin, pivot);
    pivot = begin;
    int right = 0;

    while (begin <= end) {
   
        if (array[begin] > array[pivot]) {
            swap(array, begin, end);
            end--;
        }
        
        else if (array[begin] == array[pivot]) {
            if (right) {
                swap(array, begin, end);
                end--;
                right = 0;
            } else {
                begin++;
                right = 1;
            }
        }
        else
            begin++;
    }
    swap(array, pivot, end);
    return end;
}



void Quick_Sort(int* array, int begin, int end){
    while (begin < end) {
        int p = Partition(array, begin, end, begin);
        
        Quick_Sort(array, begin, p - 1);
        begin = p + 1;
        
    }
}


void Quick_Sort_Best(int * array, int begin, int end){
    while (begin < end) {
        int p = Partition(array, begin, end, (begin + end) / 2);
        Quick_Sort_Best(array, begin, p - 1);
        begin = p + 1;
    }
}


/* COUNTING SORT */

void Counting_Sort(int * A, int * B, int sizeA){
    
    int sizeC = Max(A, sizeA)-Min(A, sizeA)+1;
    int * C = Array_Alloc(sizeC);
    for(int i = 0; i < sizeA; i++){
        C[A[i]-1] = C[A[i]-1]+1;
    }
    
    
    for(int j = 1; j < sizeC; j++ ){
        C[j] = C[j-1] + C[j];
    }
    
    
    for(int i = sizeA-1; i>=0; --i){
        B[C[A[i]-1]-1] = A[i];
        C[A[i]-1] = C[A[i]-1]-1;
    }
    
}

/* RADIX SORT */

void Counting_Sort_Aux(int * array, int size, int place)
{
    const int max = 10;
    int output[size];
    int count[max] = {0};
 
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
    
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];
    
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void Radix_Sort(int * array, int size)
{
    int max = Max(array, size);
    for (int place = 1; max / place > 0; place *= 10)
        Counting_Sort_Aux(array, size, place);
}

/* BUCKET SORT */

Node* Bubble_Sort( Node * first){
    int swapped;
    struct Node * ptr1;
    struct Node * lptr = NULL;
    
    if (first == NULL)
        return first;
    
    do
    {
        swapped = 0;
        ptr1 = first;
        
        while (ptr1->next != lptr)
        {
            if (ptr1->value > ptr1->next->value)
            {
                Swap_Node(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    return first;
}

void Bucket_Sort(double *array, int n)
{
    Node * B[n];
    
    for (int i = 0; i < n; i++)
        B[i] = NULL;
    
    for (int i = 0; i < n; i++) {
        int idx = floor(array[i]*n);
        B[idx] = append(B[idx],array[i]);
    }
    
    for (int i = 0; i < n; i++) B[i] = Bubble_Sort(B[i]);
    int size;
    int aux_idx=0;
    for (int i = 0; i < n; i++) {
        size = List_Size(B[i]);
        for (int j = 0; j < size; j++) {
            array[aux_idx] = Get_Value_List(B[i],j);
            aux_idx++;
        }
    }
    
   for (int i = 0; i < n; i++) {
        delete B[i] ;
    }
}


/* HEAP SORT */

void heap_sort(int * array, int size){
    
    heap H = build_max_heap(array, size);
    
    for (int i = size - 1; i >= 1; i--)
    {
        array[i] = max_remove_minimum(&H);
    }
    
}
