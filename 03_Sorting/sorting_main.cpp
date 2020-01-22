#include <iostream>
#include "include/array_utilities.hpp"
#include "include/sorting.hpp"


int main(){
    
    std::cout << ">>>> Insertion sort <<<< \n";
    std::cout << "Inster the size of the array to sort: \n";
    int size;
    std::cin >> size;
    int * A{new int[size]};
    std::cout << "Insert the array's elements\n";
    for(int i = 0; i < size; i++){
        std::cin >> A[i];
    }
    
    insertion_sort(A, size);
    
    std::cout << "Sorted array: \n";
    
    Array_Print(A, size);
    
    int size2 = 8;
    int * Array = new int[size2];
    for(int i{0}; i < size2; i++){
        Array[i] = size2 - i;
    }
    Array_Print(Array, size2);
    Quick_Sort(Array, size2);
    Array_Print(Array, size2);
    
}
