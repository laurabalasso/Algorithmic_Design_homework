/*
 
 Implementation of array-based Dijkstra algorithm
 
 */

#ifndef Dijkstra_array_hpp
#define Dijkstra_array_hpp

#include <climits>
#include <iostream>
#include <cstdlib>

#include "dijkstra_utility.hpp"


/* Array-representaition of a priority queue */
struct Queue{
    
    Node ** array;
    int N;
    
};

/* function that creates a Queue from an array of nodes */
Queue * create_queue(Node * nodes, int N);


bool is_q_empty(Queue * q);

/* function that removes the i-th node from the queue */
void dequeue_node(Queue * q, int i);

/* function that extracts the minimum from the queue */
Node * extract_min(Queue * q);

void relax(Node* u, Node* v, int weight);

void dijkstra_array(Graph *g, int start);


#endif /* Dijkstra_array_hpp */
