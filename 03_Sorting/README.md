# Homework 3: Sorting

* Implement Insertion Sort and Quick Sort.
  
* Implement Heap Sort by using binary heap implementation required by the homework on heaps.
  
* Implement Counting Sort, Radix Sort, and Bucket Sort.

* Implement the Select Algorithm.

* Test the implementations on a set of instances of the problem and evaluate their execution times.

* Prove by testing that both Insertion Sort and Quick Sort take time `O(n^2)` in the worst case.

* Prove by testing that Insertion Sort and Quick Sort take in the best case time `O(n)` and `O(n log n)` respectively.

* Why did we assume that there were no repeated values in A? Generalize the implementation of the Select Algorithm to also deal with repeated values.


### In this folder

The implementation of all the above sorting algorithms can be found in the file `src/sorting.cpp` except for the Select algorithm
which is implemented in `src/Select.cpp`. 

The file `src/array_utilities.cpp` contains some utility functions useful to deal with arrays.

The file `src/heap.cpp` contains an implementation of a max heap, needed for the heap sort.

Use the command `make` to compile the code. Three executables will be produced:
* `sorting_main.x` tests the correctness of the implementations, by applying the algorithms to a random-filled array and printing the solution
* `sorting_tests.x` shows the execution time of each implementation for different array sizes. In particular, can be noticed that the execution time of insertion sort and quick sort is `O(n^2)` in the worst case and respectively `O(n)` and `O(n log n)` in the best case. This behaviour is also shown graphically in the folder `results`
* `select_main.x` shows the execution time (for random-filled arrays of different sizes) of the select algorithm implemented in `src/Select.cpp`
