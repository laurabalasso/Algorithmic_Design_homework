/*
 
 Implementation of a min heap where the heap's components are objects of type Node (definition in dijkstra_utility.hpp).
 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "../include/heap.hpp"
#include "../include/dijkstra_utility.hpp"


#define INFINITY INT_MAX


/* function to swap elements of a heap */
void swap(Node** a, Node** b){
    
    int pos = (**a).position;
    (**a).position = (**b).position;
    (**b).position = pos;
    
    Node* temp = *a;
    *a = *b;
    *b = temp;
}


/* function that returns the index of the left child */
int left(int i){
    return 2*i+1;
}

/* function that returns the index of the right child */
int right(int i){
    return 2*i+2;
}

/* function that returns the index of the parent node */
int parent(int i){
    return i/2;
}

/* function that returns the index of the root */
int get_root(){
    return 0;
}

/* boolean function to check if i is the root index */
bool is_root(int i){
    return i==0;
}

/* boolean function to check if the heap is empty */

bool is_empty(heap * H){
    return (H->size == 0);
}

/* boolean function to check if i is valid node index */
bool is_valid_node(heap * H, int i){
    return i <= (H->size -1);
}

/* function that returns the heap's minimum element */
Node * heap_min(heap &H){
    return H.array[get_root()];
}


/*iterative version of HEAPIFY for Min Heap*/

void min_heapify(heap * H, int i){
    int m = i;
    int k = -1;
    while (k!=m){
        k = m;
        int children[2] = {left(k),right(k)};
        for (int j = 0; j < 2; j++)
            if (is_valid_node(H, children[j]) && ((H->array[children[j]]->distance) <= (H->array[m]->distance)))
                m = children[j];
        if (k!=m)
            swap(&(H->array[k]),&(H->array[m]));
    }
}



/* function that extracts the min heap minimum preserving the heap property */
Node * extract_minimum(heap * H){
    Node * min = H->array[0];
    H->array[0] = H->array[H->size - 1];
    H->size --;
    if(H->size > 0) min_heapify(H, 0);
    return min;
}


/* function that builds a min heap from an array of a given size */

heap * build_min_heap(Node * arr, int size)
{
    Node ** nodes_array = new Node*[size];
    for (int i= 0; i< size; i++){
        arr[i].position = i;
        nodes_array[i] = &(arr[i]);
    }

    heap *  H =  new heap;
    H->size = size;
    H->array = nodes_array;

    int last = parent(H->size-1);
    for(int i = last ; i>=0; i--){
        min_heapify(H, i);
    }
    return H;
}


/* function that decrease the value of a given node of a min heap preserving the heap property */
void decrease_key(heap * H, int i, int val){
    
    H->array[i]->distance = val;
    
    while(!is_root(i) && H->array[parent(i)] > H->array[i]){
        swap(&(H->array[i]),&(H->array[parent(i)]));
        i = parent(i);
    }
}



void update_distance(heap * H, Node* v, int w)
{
    int pos = v->position;
    decrease_key(H, pos, w);
}


