#include <iostream>
#include <climits>
#include "include/array_utilities.hpp"
#include "include/sorting.hpp"


int main(){
    
    int size = 10;
    int * A{new int[size]};
    
    /* INSERTION SORT */
    
    Random_Fill(A, size, 20);
    
    insertion_sort(A, size);
    
    std::cout << "Insertion sort: \n";
    
    Array_Print(A, size);
    
    /*  QUICK SORT */
    
    Random_Fill(A, size, 20);
    
    Quick_Sort(A, size);
    
    std::cout << "Quick sort: \n";
    
    Array_Print(A, size);
    
    /* COUNTING SORT */
    
    Random_Fill(A, size, 20);
    
    int * B = Array_Alloc(size);
    
    Counting_Sort(A, B, size);
    
    std::cout << "Counting sort: \n";
    
    Array_Print(B, size);
    
    /* COUNTING SORT */
    
    Random_Fill(A, size, 20);
    
    Radix_Sort(A, size);
    
    std::cout << "Radix sort: \n";
    
    Array_Print(A, size);
    
    /* BUCKET SORT */
    
    double * D = new double[size];
    
    Random_Fill_Double(D, size);
    
    Bucket_Sort(D, size);
    
    std::cout << "Bucket sort: \n";
    
    Array_Print(D, size);

    std::cout<< "\n";
    
    
}
