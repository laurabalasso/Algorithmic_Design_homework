#include "include/Dijkstra_array.hpp"
#include "include/Dijkstra_heap.hpp"

#include <time.h>
#include <chrono>
#include <iostream>

double getExecutionTime(const struct timespec b_time, const struct timespec e_time){
    return (e_time.tv_sec-b_time.tv_sec) +
    (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}


int ** init_random_matrix(int size) {
    int ** M = new int*[size];
    
    for(int i = 0; i < size; i++){
        M[i] = new int[size];
        for(int j = 0; j < size; j++)
            M[i][j] = (int)(rand() % 20 +1);
    }
    
    return M;
}



int main(){
    

    int size = 10;
    
    std::cout << "Dijkstra algorithm applied to a simple graph with " << size << " nodes \n";
    
    int ** adj_matrix = new int*[size];
    for(int i = 0; i < size ; i++){
        adj_matrix[i] = new int[size];
    }
    
    init_adjacency_matrix(adj_matrix, size);
    
    adj_matrix[0][1] = 1;
    adj_matrix[0][2] = 5;
    adj_matrix[1][5] = 15;
    adj_matrix[2][3] = 2;
    adj_matrix[3][2] = 7;
    adj_matrix[3][4] = 1;
    adj_matrix[4][5] = 3;
    adj_matrix[4][6] = 2;
    adj_matrix[3][7] = 11;
    adj_matrix[7][8] = 2;
    adj_matrix[1][8] = 9;
    adj_matrix[8][9] = 1;
    adj_matrix[9][6] = 7;
    
    std::cout << "Adjacency matrix:\n\n";
    
    print_matrix(adj_matrix, size);
    
     /* ARRAY-BASED */
    
    Graph * g_a = new Graph;
    
    g_a->init_graph(adj_matrix, size);
    
    auto start = std::chrono::high_resolution_clock::now();
    dijkstra_array(g_a, 0);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "\nArray-based solution: \n";
    g_a->print_graph();
    
    auto d = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    std::cout<<"Time to execute the array-based algorithm: "<< d << " nanoseconds\n " ;
    
    /* HEAP-BASED */
    
    Graph * g_h = new Graph;

    g_h->init_graph(adj_matrix, size);
    
    start = std::chrono::high_resolution_clock::now();
    dijkstra_heap(g_h, 0);
    end = std::chrono::high_resolution_clock::now();
    
    std::cout << "\nHeap-based solution: \n";
    g_h->print_graph();
    
    d = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    std::cout<<"Time to execute the heap-based algorithm: "<< d << " nanoseconds\n\n" ;
    
    /* RANDOM ADJACENCY MATRIX */
    
    struct timespec start_r, end_r;
    
    double exec_time_array;
    double exec_time_heap;
    
    Graph * g_r_a = new Graph;
    Graph * g_r_h = new Graph;
    
    int ** adj_random;
    
    std::cout << "Dijkstra algorithm applied to graphs with different number of nodes with random adjacency marix\n";
    std::cout << "N nodes \t array \t\t heap \n";
    
    int sizes[9] = { 200, 800, 1000, 1500, 2000, 3000, 5000, 8000, 10000};
    
    for(int i = 0; i < 9 ; i++){
        
        int n = sizes[i];
        
        adj_random = init_random_matrix(n);
        g_r_a -> init_graph(adj_random, n);
        
        clock_gettime(CLOCK_REALTIME, &start_r);
        dijkstra_array(g_r_a, 0);
        clock_gettime(CLOCK_REALTIME, &end_r);
        exec_time_array = getExecutionTime(start_r, end_r);

        
        g_r_h -> init_graph(adj_random, n);
        clock_gettime(CLOCK_REALTIME, &start_r);
        dijkstra_heap(g_r_h, 0);
        clock_gettime(CLOCK_REALTIME, &end_r);

        exec_time_heap = getExecutionTime(start_r, end_r);

        
        std::cout << n << "\t\t" << exec_time_array << "\t" << exec_time_heap << std::endl;
    }
    
    
    return 0;
}
