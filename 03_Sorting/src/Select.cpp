#include <cstdlib>
#include <iostream>
#include "../include/Select.hpp"
#include "../include/array_utilities.hpp"
using namespace std;


void insertion_sort(int * array, int start, int size)
{
    int j;
    for(int i = start + 1; i < size; i++)
    {
        j = i;
        while (j > start && array[j] < array[j-1])
        {
            swap(array, j-1, j);
            j--;
        }
    }
}

int min(int a, int b)
{
    return a>b ? b : a;
}



int partition(int * array, int low, int high, int pivot)
{
    swap(array, low, pivot);
    int i = low + 1;
    int j = high - 1;
    pivot = low;
    int side = 1;
    
    while(i <= j)
    {
        if (array[i] == array[pivot])
        {
            side = !side;
        }
        if(array[i] > array[pivot] || array[i] == (array[pivot] && !side))
        {
            swap(array, i, j);
            --j;
        }
        else
        {
            i++;
        }
    }
    swap(array, pivot, j);
    return j;
}

int select_pivot(int * array, int low, int high)
{
  
    if(high - low < 5)
    {
        insertion_sort(array, low, high);
        return (low + high) / 2;
    }

    int chunks = (high - low) / 5 + 1;
    
    for (int i = 0; i < chunks; i++)
    {
        insertion_sort(array, 5 * i + low, min(5 * i + low + 4, high));
    }
    for (int i = 0; i < chunks; i++)
    {
        swap(array, low + i, min(5 * i + low + 2, high - 1));
    }
    return select_pivot(array, low, low + chunks);
}


int select_aux(int * array, int low, int high, int i)
{
    int j = select_pivot(array, low, high);
    int k = partition(array, low, high, j);
    
    if(i == k)
    {
        return array[k];
    }
    if(i < k)
    {
        return select_aux(array, low, k, i);
    }
    return select_aux(array, k + 1, high, i);
}



int selection(int * A, int i, int N){
    
    return select_aux(A, 0, N, i);
}
