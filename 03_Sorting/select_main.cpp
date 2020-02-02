#include <iostream>
#include <time.h>

#include "include/Select.hpp"
#include "include/array_utilities.hpp"

int * select_sort(int * A, int size){
    
    int * sorted = new int[size];
    
    for(int i = 0; i < size ; i++ )
        sorted[i] = selection(A, i, size);

    return sorted;
}

int main(){
    
    int * A;
    int sizes[7] = {200, 500, 1000, 1500, 2000, 3000, 4000};
    double exec_time;
    
    std::cout << "Size\tSelect execution time\n---------------------------------------------\n";
    
    for(int i = 0; i< 7; i++){
        int n = sizes[i];
        
        A = new int[n];
        
        Random_Fill(A, n, 100);
        
        struct timespec start, end;
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        int * result = select_sort(A, n);
        clock_gettime(CLOCK_MONOTONIC, &end);

        exec_time = (end.tv_sec - start.tv_sec) * 1e9;
        exec_time = (exec_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
        std::cout << n << "\t" << exec_time << std::endl;
        
    }
    
    
}
