/*
 
 Implementation of a min heap where the heap's components are objects of type Node (definition in dijkstra_utility.hpp).
 
 */


#ifndef __HEAP__
#define __HEAP__

#include "dijkstra_utility.hpp"

/* definition of heap type */
struct heap
{
    Node ** array;
    int size;
};


/* function to swap elements of a heap */
void swap(Node** a, Node** b);

/* function that returns the index of the left child */
int left(int i);

/* function that returns the index of the right child */
int right(int i);

/* function that returns the index of the parent node */
int parent(int i);

/* function that returns the index of the root */
int get_root();

/* boolean function to check if i is the root index */
bool is_root(int i);

/* boolean function to check if the heap is empty */
bool is_empty(heap * H);

/* boolean function to check if i is valid node index */
bool is_valid_node(heap * H, int i);

/* function that returns the heap's minimum element */
Node * heap_min(heap &H);


/* iterative implementation of HEAPIFY */
void min_heapify(heap * H, int m);


/* function that extracts the heap's minimum preserving the heap property */
Node * extract_minimum(heap * H);


/* function that builds a heap from an array of a given size */
heap * build_min_heap(Node * arr, int size);

/* function that decrease the value of a given node preserving the heap property */
void decrease_key(heap * H, int i, int val);


void update_distance(heap * H, Node * v, int w);

#endif
