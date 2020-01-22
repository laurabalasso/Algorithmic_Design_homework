#include <iostream>
#include "../include/array_utilities.hpp"


void swap(int * A, const int& i ,const int& j){
    int temp{A[i]};
    A[i] = A[j];
    A[j] = temp;
}

void Array_Print(int* A, int N){

    for(int i{0}; i < N; i++){
            std::cout<< A[i] << "   ";
        }

    std::cout<< "\n";
}

int * Array_Alloc(int size){
    int * A = new int[size];
    for(int i = 0; i < size; i++){
        A[i] = 0;
    }
    return A;
}


int Min(int * A, int size){
    int min = A[0];
    for(int i = 1; i < size; i++ ){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Max(int * A, int size){
    int max = A[0];
    for(int i = 1; i<size; i++){
        if(A[i] > max){
            max = A[i]; 
        }
    }
    return max;
}
