# Homework 1: Matrix Multiplication

### Assignment
Compile the provided implementation of the Strassen's algorithm using `cc -O4 -o strassen_test  *.c`, 
then produce an improved version of the code by reducing the memory allocations and test the effects on the execution time.
 
### In this folder
The improved version of the Strassen's algorithm implementation can be found in the file `src/Strassen_improved.cpp` with header
`include/Strassen_improved.hpp`.



Into the `results` folder there are a file txt with the execution times for different matrix sizes of the naive matrix multiplication,
the Strassen and the improved Strassen. A graphic representation of the execution times is also provided, showing that the improved 
version performs better with lage-sized matrices, thanks to optimized memory allocation.


Use the command `make` to compile the code and obtain an executable named `main.x`.
