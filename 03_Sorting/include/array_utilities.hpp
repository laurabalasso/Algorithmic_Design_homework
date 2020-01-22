#ifndef __UTILITIES__
#define __UTILITIES__

/*
function to swap two elements in an array given their index 
*/
void swap(int * A, const int& i ,const int& j);


/*
function to print an array of a given size
*/
void Array_Print(int* A, int N);

/*
function to allocate an array dynamically and initialize its elements to zero
*/
int * Array_Alloc(int size);

/*
function to find the minimum in an array
*/
int Min(int * A, int size);

/*
function to find the maximum in an array
*/
int Max(int * A, int size);

/*
function to fill an array with random numbers between 1 and rand_max
 */
void Random_Fill(int * A, int size, int rand_max);

#endif

