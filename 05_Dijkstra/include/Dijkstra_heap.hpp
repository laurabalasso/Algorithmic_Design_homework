/*
 
 Implementation of heap-based Dijkstra algorithm
 
 */

#ifndef Dijkstra_heap_hpp
#define Dijkstra_heap_hpp

#include <climits>
#include <iostream>
#include <cstdlib>
#include "heap.hpp"

#include "dijkstra_utility.hpp"


void relax(heap * q, Node* u, Node* v, int w);

void dijkstra_heap(Graph *g, int start);


#endif /* Dijkstra_heap_hpp */
