#ifndef __HEAP__
#define __HEAP__

/* definition of heap type */
struct heap
{
    int * array;
    int size;
};


/* function to swap elements of a heap */
void swap(heap * H, int i, int j);

/*function that fills a given array with random integers from 1 to 20*/
void random_ints(int * array, int size);

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

/* boolean function to check if i is valid node index */
bool is_valid_node(heap * H, int i);

/* function that returns the heap's minimum element */
int heap_min(heap &H);


/* iterative implementation of HEAPIFY */
void min_heapify(heap * H, int i);

void max_heapify(heap * H, int i);

/* function that removes the heap's minimum preserving the heap property */
int min_remove_minimum(heap * H);

int max_remove_minimum(heap * H);

/* function that builds a heap from an array of a given size */
heap build_min_heap(int * arr, int size);

heap build_max_heap(int * arr, int size);

/* function that decrease the value of a given node preserving the heap property */
void min_heap_decrease_key(heap * H, int i, int val);

void max_heap_decrease_key(heap * H, int i, int val);


/* function that inserts a new element in the heap preserving the heap property */
void min_heap_insert(heap * H, int val);

void max_heap_insert(heap * H, int val);


#endif
