/* 
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. 
It is given that all array elements are distinct.
*/

// Using Min Heap - HeapSelect

#include <bits/stdc++.h>
using namespace std;


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap // A class for Min Heap
{
private:
    int* heap_arr; // pointer to the array of elements in heap.
    int capacity; // maximum possible size of min heap
    int heap_size; // maximum possible size of min heap
public:
    MinHeap(int a[], int size); // Constructor
};

MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    heap_arr = a; // point to the array.

    int i = 6;
}