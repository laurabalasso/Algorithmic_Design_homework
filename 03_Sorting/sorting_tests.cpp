#include <time.h>
#include <climits>
#include <iostream>

#include "include/array_utilities.hpp"
#include "include/sorting.hpp"

using namespace std;

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
    return (e_time.tv_sec-b_time.tv_sec) +
    (e_time.tv_nsec-b_time.tv_nsec)/1E9;
    
}

int main(){
    
    const int NUM_SIZE = 5;
    int sizes[NUM_SIZE] = {10000, 20000, 40000, 60000, 80000};
    
    int * insertionArray;
    int * bestInsertionArray;
    int * worstInsertionArray;
    
    int * quickArray;
    int * bestQuickArray;
    int * worstQuickArray;
    
    int * countArray;
    int * radixArray;
    int * heapArray;
    
    double * bucketArray ;
    
    /* Time measures */
    
    double insertionTime, bestInsertionTime, worstInsertionTime;
    double quickTime, bestQuickTime, worstQuickTime;
    double countingTime, radixTime, bucketTime, heapTime;

    
    std::cout << "N \t Insertion Sort \t Worst Insertion \t Best Insertion \t Quick Sort \t Worst Quick \t Best Quick \tCounting Sort\tRadix Sort\t Bucket Sort\t Heap Sort\n" ;

    
    for(int i = 0; i < NUM_SIZE; i++){
        
        int n = sizes[i];
        
        struct timespec start, end;
        
        /* INSERTON SORT */
        
        insertionArray  = new int[n];
        Random_Fill(insertionArray, n, 50);
        clock_gettime(CLOCK_MONOTONIC, &start);
        insertion_sort(insertionArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        insertionTime = get_execution_time(start, end);
        delete[] insertionArray;
        
        /* Worst case: array sorted in descending order */
        
        worstInsertionArray = new int[n];
        Random_Fill(worstInsertionArray, n, 100);
        reverse_order(worstInsertionArray, n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        insertion_sort(worstInsertionArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        worstInsertionTime = get_execution_time(start, end);
        delete[] worstInsertionArray;
        
        /* Best case: array sorted in ascending order */
        bestInsertionArray = new int[n];
        Random_Fill(bestInsertionArray, n, 100);
        insertion_sort(bestInsertionArray, n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        insertion_sort(bestInsertionArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        bestInsertionTime = get_execution_time(start, end);
        delete[] bestInsertionArray;
        
        
        
        /* QUICK SORT */
        
        /* Average case: random filled array, pivot = first element */
        quickArray = new int[n];
        Random_Fill(quickArray, n, 50);
        clock_gettime(CLOCK_MONOTONIC, &start);
        Quick_Sort(quickArray, 0, n-1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        quickTime = get_execution_time(start, end);
        delete[] quickArray;
        
        
        /* Worst case: array is sorted (in ascending or descending order) and the pivot is the fist or the last element */
        worstQuickArray = new int[n];
        Random_Fill(worstQuickArray, n, 100);
        reverse_order(worstQuickArray, n);//descending order
        clock_gettime(CLOCK_MONOTONIC, &start);
        Quick_Sort(worstQuickArray, 0, n-1); //first element pivot
        clock_gettime(CLOCK_MONOTONIC, &end);
        worstQuickTime = get_execution_time(start, end);
        delete[] worstQuickArray;
        
        /* Best case: the pivot is the central element and the array is sorted */
        bestQuickArray = new int[n];
        Random_Fill(bestQuickArray, n, 100);
        insertion_sort(bestQuickArray, n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        Quick_Sort_Best(bestQuickArray,0, n-1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        bestQuickTime = get_execution_time(start, end);
        delete[] bestQuickArray;
        
        /* COUNTING SORT */
        countArray = new int[n];
        Random_Fill(countArray, n, 50);
        int * auxArray = Array_Alloc(n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        Counting_Sort(countArray, auxArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        countingTime = get_execution_time(start, end);
        delete[] countArray;
        
        /* RADIX SORT */
        radixArray = new int[n];
        Random_Fill(radixArray, n, 50);
        clock_gettime(CLOCK_MONOTONIC, &start);
        Radix_Sort(radixArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        radixTime = get_execution_time(start , end);
        delete[] radixArray;
        
        /* BUCKET SORT */
        
        bucketArray = new double[n];
        Random_Fill_Double(bucketArray, n);
        clock_gettime( CLOCK_MONOTONIC, &start);
        Bucket_Sort(bucketArray, n);
        clock_gettime( CLOCK_MONOTONIC, &end);
        bucketTime = get_execution_time(start, end);
        delete[] bucketArray;
        
        /* HEAP SORT */
        heapArray = new int[n];
        Random_Fill(heapArray, n, 50);
        clock_gettime(CLOCK_MONOTONIC, &start);
        heap_sort(heapArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        heapTime = get_execution_time(start, end);
        
        delete[] heapArray;
        
        
        std::cout<< n << "\t  ";
        std::cout << insertionTime << "\t\t " << worstInsertionTime << "  \t\t  " << bestInsertionTime << "  \t\t " << quickTime << "\t     " << worstQuickTime << "\t " << bestQuickTime << "\t" << countingTime << "  \t " << radixTime << "\t  " << bucketTime << "\t " << heapTime  << "\n";

        
    }
    
}
