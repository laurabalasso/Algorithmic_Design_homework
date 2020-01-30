#include <iostream>
#include <climits>
#include "include/array_utilities.hpp"
#include "include/sorting.hpp"
#include "include/Select.hpp"


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
    
    Quick_Sort(A, 0, size-1);
    
    std::cout << "Quick sort: \n";
    
    Array_Print(A, size);
    
    Random_Fill(A, size, 20);
    
    Quick_Sort_Best(A, 0, size-1);
    
    std::cout << "Best case quick sort: \n";
    
    Array_Print(A, size );
    
    
    /* COUNTING SORT */
    
    Random_Fill(A, size, 20);
    
    int * B = Array_Alloc(size);
    
    Counting_Sort(A, B, size);
    
    std::cout << "Counting sort: \n";
    
    Array_Print(B, size);
    
    /* RADIX SORT */
    
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
    
    /* SELECT */
    
    std::cout << "Select: \n";
    
    Random_Fill(A, size, 20);
    Array_Print(A,size);
    std::cout<< "\n";
    for(int p=0;p<size;p++) std::cout<< selection(A, p, size) << std::endl;
    
}
