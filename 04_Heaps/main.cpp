#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "include/heap.hpp"

#define INFINITY INT_MAX

int main(){

    size_t N = 10;
    int * arr=new int[N];
    random_ints(arr, N);

    std::cout << "heap H1 array: \n";
    for(int i=0; i<N; i++){
        std::cout << arr[i] << std::endl;
    }

    heap H1 = build_max_heap(arr, N);

    std::cout << "heap H1 size: " << H1.size << std::endl;
    std::cout << "\n";

    
    std::cout << "heapified H1 array: \n";
    for(int i=0; i<N;i++){
        std::cout << H1.array[i] << std::endl;
    }
    
    max_remove_minimum(&H1);
    std::cout << "removed H1 minimum: \n";
    for(int i=0; i< N-1 ;i++){
        std::cout << H1.array[i] << std::endl;
    }

    max_heap_decrease_key(&H1, 2, 20);

    std::cout << "decreased key of H[2]: \n";
    for(int i=0; i< N-1 ;i++){
        std::cout << H1.array[i] << std::endl;
    }



    return 0;
}
