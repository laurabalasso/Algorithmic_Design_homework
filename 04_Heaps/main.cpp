#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <time.h>
#include "include/heap.hpp"

#define INFINITY INT_MAX

int main(){

    size_t N = 10;
    int * arr=new int[N];
    random_ints(arr, N);
    
    std::cout << ">>>\tMAX HEAP TESTS\t<<<\n\n";

    std::cout << "max heap H array: \n";
    for(int i=0; i<N; i++){
        std::cout << arr[i] << "   ";
    }
    std::cout << "\n";

    heap H1 = build_max_heap(arr, N);

    std::cout << "heap H size: " << H1.size << std::endl;
    std::cout << "\n";

    
    std::cout << "heapified H array: \n";
    for(int i=0; i<N;i++){
        std::cout << H1.array[i] << "   ";
    }
    std::cout << "\n";
    std::cout << "\n";
    
    max_remove_minimum(&H1);
    std::cout << "removed H minimum: \n";
    for(int i=0; i< N-1 ;i++){
        std::cout << H1.array[i] << "   ";
    }
    std::cout << "\n";
    std::cout << "\n";
    
    max_heap_decrease_key(&H1, 2, 20);

    std::cout << "decreased key of H[2]: \n";
    for(int i=0; i< N-1 ;i++){
        std::cout << H1.array[i] << "   ";
    }
    std::cout << "\n";
    std::cout << "\n";

    /* execution time */
    
    int * A;
    int sizes[10] = { 1000,  2000,  4000,  8000, 10000, 20000, 50000, 80000, 100000, 200000};
    struct timespec start, end;
    double exec_time;
    
    std::cout << "Time in seconds to build a max heap from an array of size N\n\n";
    std::cout << "N\texecution time\n";
    
    for (int i = 0; i < 10; i++){
        int n = sizes[i];
        
        A = new int[n];
        
        for(int i = 0; i < n; i++){
            A[i] = (rand() % 100) + 1;
        }
        
        clock_gettime(CLOCK_REALTIME, &start);
        heap H = build_max_heap(A, n);
        clock_gettime(CLOCK_REALTIME, &end);
        
        exec_time = (end.tv_sec - start.tv_sec) * 1e9;
        exec_time = (exec_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
        std::cout << n << "\t" << exec_time << std::endl;
    }

    return 0;
}
