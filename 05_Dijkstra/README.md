# Homework 5: Weighted Graphs

* Implement the array-based version of the Dijkstra's algorithm

* Implement the binary heap-based version of the Dijkstra's algorithm.

* Test the implementations on a set of instances of the problem and compare their execution times.

### In this folder
The array-based and the heap-based algorithm are implemented respectively in `src/Dijkstra_array.cpp` and `src/Dijkstra_heap.cpp`.

In the file `src/heap.cpp` is implemented a different version of a max heap, based on an array of objects of type Node. 

In the file `src/dijkstra_uility.cpp` are implemented functions and data structures that needed for both the heap-based and the 
array-based implementations.

Compile the code with the command `make`. By running the executable two tests' results will be printed:
* The execution time and the algorithm's solution of both the implementations, given an andjacency matrix representing a simple graph, which is 
graphically represented in the image `weighted_graph.png`.
* The execution time of both the implementations given a random-generated adjacency matrix, for different numbers of nodes.
