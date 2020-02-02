#include <iostream>
#include <climits>
#include <time.h>
#include <iomanip>
#include "include/array_utilities.hpp"
#include "include/sorting.hpp"


int main(){
    
    /* Arrays initialization */
    const int NUM_SIZE = 6;
    int size[NUM_SIZE] = {10000,20000,40000,60000,80000,90000};
    
    int * insertionArray;
    int * bestInsertion;
    int * worstInsertion;
    
    int * quickArray ;
    int * bestQuick;
    int * worstQuick;
    
    int * countArray;
    int * radixArray;
    int * heapArray;
    
    double * bucketArray ;
    
    /* Time measures */
    
    double insertionTime, insertionTimeBest, insertionTimeWorst;
    double quickTime, quickTimeBest, quickTimeWorst;
    double countingTime, radixTime, bucketTime, heapTime;
    
    std::cout << "N \t Insertion Sort \t Worst Insertion \t Best Insertion \t Quick Sort \t Worst Quick \t Best Quick \tCounting Sort\tRadix Sort\t Bucket Sort\t Heap Sort\n" ;
    
    
    for(int i = 0; i < NUM_SIZE; i++){
        
        int n = size[i];
        
        insertionArray = new int[n];
        bestInsertion = new int[n];
        worstInsertion = new int[n];
        
        quickArray = new int[n] ;
        bestQuick= new int[n];
        worstQuick = new int[n];
        
        countArray = new int[n];
        radixArray = new int[n];
        bucketArray = new double[n];
        heapArray = new int[n];
        
        Random_Fill(insertionArray, n, 100);
        Random_Fill(quickArray, n, 100);
        Random_Fill(countArray, n, 100);
        Random_Fill(radixArray, n, 100);
        Random_Fill_Double(bucketArray, n);
        Random_Fill(heapArray, n, 100);
        
        
        struct timespec start, end;
        
        /* INSERTION SORT */
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        insertion_sort(insertionArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        insertionTime = (end.tv_sec - start.tv_sec) * 1e9;
        insertionTime = (insertionTime + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
        
        /* Worst case: array sorted in descending order */
        
        fill_descending(worstInsertion, n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        insertion_sort(worstInsertion, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        insertionTimeWorst = (end.tv_sec - start.tv_sec) * 1e9;
        insertionTimeWorst = (insertionTimeWorst + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
        
        /* Best case: array sorted in ascending order */
        fill_ascending(bestInsertion, n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        insertion_sort(bestInsertion, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        insertionTimeBest = (end.tv_sec - start.tv_sec) * 1e9;
        insertionTimeBest = (insertionTimeBest + (end.tv_nsec - start.tv_nsec)) * 1e-9;
       
        
        /* QUICK SORT */
        
        /* Average case: random filled array, pivot = first element */
        clock_gettime(CLOCK_MONOTONIC, &start);
        Quick_Sort(quickArray, 0, n-1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        quickTime = (end.tv_sec - start.tv_sec) * 1e9;
        quickTime = (quickTime + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
      
        /* Worst case: array is sorted (in ascending or descending order) and the pivot is the fist or the last element */
        fill_descending(worstQuick, n); //descending order
        clock_gettime(CLOCK_MONOTONIC, &start);
        Quick_Sort(worstQuick, 0, n-1); //first element pivot
        clock_gettime(CLOCK_MONOTONIC, &end);
        quickTimeWorst = (end.tv_sec - start.tv_sec) * 1e9;
        quickTimeWorst = (quickTimeWorst + (end.tv_nsec - start.tv_nsec)) * 1e-9;
       
        
        
        
        /* Best case: the pivot is the central element and the array is sorted */
        fill_ascending(bestQuick, n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        Quick_Sort_Best(bestQuick,0, n-1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        quickTimeBest =(end.tv_sec - start.tv_sec) * 1e9;
        quickTimeBest = (quickTimeBest + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        

        
        
        /* COUNTING SORT */
        int * auxArray = Array_Alloc(n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        Counting_Sort(countArray, auxArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        countingTime =(end.tv_sec - start.tv_sec) * 1e9;
        countingTime = (countingTime + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
        
        /* RADIX SORT */
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        Radix_Sort(radixArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        radixTime = (end.tv_sec - start.tv_sec) * 1e9;
        radixTime = (radixTime + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
        
        
        /* BUCKET SORT */
        
        clock_gettime( CLOCK_MONOTONIC, &start);
        Bucket_Sort(bucketArray, n);
        clock_gettime( CLOCK_MONOTONIC, &end);
        bucketTime = (end.tv_sec - start.tv_sec) * 1e9;
        bucketTime = (bucketTime + (end.tv_nsec - start.tv_nsec)) * 1e-9;
       
        
        /* HEAP SORT */
        clock_gettime(CLOCK_MONOTONIC, &start);
        heap_sort(heapArray, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        heapTime = (end.tv_sec - start.tv_sec) * 1e9;
        heapTime = (heapTime + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
        
        /* execution times */
        
        std::cout<< n << "\t  ";
        std::cout<< std::setprecision(8)  << insertionTime << "\t\t " << insertionTimeWorst << "\t\t  " << insertionTimeBest << "\t\t " << quickTime << "\t   " << quickTimeWorst << "\t " << quickTimeBest << "\t" << countingTime << "\t " << radixTime << "\t  " << bucketTime << "\t " << heapTime  << "\n";
        
        delete[] insertionArray;
        delete[] bestInsertion;
        delete[] worstInsertion;
        delete[] quickArray;
        delete[] bestQuick;
        delete[] worstQuick;
        delete[] radixArray;
        delete[] countArray;
        delete[] bucketArray;
        delete[] heapArray;
    }
    
    

}

