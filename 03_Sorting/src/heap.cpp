#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "../include/heap.hpp"

#define INFINITY INT_MAX


/* function to swap elements of a heap */
void swap(heap * H, int i, int j){
    int tmp = H->array[i];
    H->array[i] = H->array[j];
    H->array[j] = tmp;
}

/*function that fills a given array with random integers from 1 to 20*/
void random_ints(int * array, int size){
    srand(time(NULL));  // set always a different seed 
    for(int i = 0; i < size; i++){
        array[i] = (rand()%20)+1;
    }
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

/* boolean function to check if i is valid node index */
bool is_valid_node(heap * H, int i){
    return H->size >= i;
}

/* function that returns the heap's minimum element */
int heap_min(heap &H){
    return H.array[get_root()];
}



/*iterative version of HEAPIFY for Min Heap*/

void min_heapify(heap * H, int i){
    int m = i;
    int k;
    bool cont = true;

    while(cont == true){
        k = m;
        int children[2] = {left(k), right(k)};
        for(int j = 0; j<2; j++){
            if(is_valid_node(H, children[j]) && H->array[children[j]] < H->array[m])
                m = children[j];
        }
        if(m != k){
            swap(H, k, m);
        }
        else
        {
            cont = false;
        }
    }
}

/*iterative version of HEAPIFY for Max Heap*/

void max_heapify(heap * H, int i){
    int m = i;
    int k;
    bool cont = true;
    
    while(cont == true){
        k = m;
        int children[2] = {left(k), right(k)};
        for(int j = 0; j<2; j++){
            if(is_valid_node(H, children[j]) && H->array[children[j]] >= H->array[m])
                m = children[j];
        }
        if(m != k){
            swap(H, k, m);
        }
        else
        {
            cont = false;
        }
    }
}



/* function that removes the min heap minimum preserving the heap property */
int min_remove_minimum(heap * H){
    int min = H->array[0];
    H->array[0] = H->array[(H->size)-1];
    H->size = (H->size)-1;
    min_heapify(H, 0);
    return min;
}

/* function that removes the max heap minimum preserving the heap property */
int max_remove_minimum(heap * H){
    int min = H->array[0];
    H->array[0] = H->array[(H->size)-1];
    H->size = (H->size)-1;
    max_heapify(H, 0);
    return min;
}


/* function that builds a min heap from an array of a given size */

heap build_min_heap(int * arr, int size)
{
    heap H = {arr , size};
    for(int i = size ; i>=0; i--){
        min_heapify(&H, i);
    }
    return H;
}

/* function that builds a max heap from an array of a given size */

heap build_max_heap(int * arr, int size)
{
    heap H = {arr , size};
    for(int i = size-1 ; i>=0; --i){
        max_heapify(&H, i);
    }
    return H;
}



/* function that decrease the value of a given node of a min heap preserving the heap property */
void min_heap_decrease_key(heap * H, int i, int val){
    if(H->array[i] <= val){
        std::cout << "Error! The new value is not smaller than H[" << i << "] \n";
        return;
    }
    
    H->array[i] = val;
    
    while(!is_root(i) && H->array[parent(i)] > H->array[i]){
        swap(H, i, parent(i));
        i = parent(i);
    }
}

/* function that decrease the value of a given node of a max heap preserving the heap property */
void max_heap_decrease_key(heap * H, int i, int val){
    if(H->array[i] >= val){
        std::cout << "Error! The new value is not greater than H[" << i << "] \n";
        return;
    }
    
    H->array[i] = val;
    
    while(!is_root(i) && H->array[i] >= H->array[parent(i)]){
        swap(H, i, parent(i));
        i = parent(i);
    }
}


/* function that inserts a new element in the heap preserving the heap property */
void min_heap_insert(heap * H, int val){
    H->size ++;
    H->array[H->size -1] = INFINITY;
    
    min_heap_decrease_key(H, H->size -1, val);
}


/* function that inserts a new element in the heap preserving the heap property */
void max_heap_insert(heap * H, int val){
    H->size ++;
    H->array[H->size -1] = - INFINITY;
    
    max_heap_decrease_key(H, H->size -1, val);
}


