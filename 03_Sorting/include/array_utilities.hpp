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

void Array_Print(double * A, int N);

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

void Random_Fill_Double(double * A, int size);



struct Node {
    double value;
    struct Node * next;
};

void Swap_Node( Node * a, Node * b);

void Bucket_Print(Node * const head);

int List_Size(Node * const head);

Node * append(Node *head, const double value);

double Get_Value_List(Node * head, int i);

void fill_descending(int * A, int n);

void fill_ascending(int * A , int n);

#endif

