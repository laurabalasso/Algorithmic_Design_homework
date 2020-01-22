#include <iostream>
#include "../include/array_utilities.hpp"
#include "../include/sorting.hpp"

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

/*  QUICK SORT  */

int Partition(int * A, int i, int j, int p){
    swap(A, i, p);
    p = i;
    i = i+1;
    while(i<=j){
        if(A[i]>A[p]){
            swap(A, i, j);
            j = j-1;
        }
        else i = i+1;
    }
    swap(A, p, j);
    return j;
}


void Quick_Sort(int * A, int N, int l){
    while(l<N){
        int p = Partition(A, l, N-1, l);
        Quick_Sort(A, p, l);
        l = p + 1;
    }
}



