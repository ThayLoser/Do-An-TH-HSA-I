#include <iostream>
#include <random>
using namespace std;

// Selection Sort #1

// Insertion Sort #2

// BinaryInsertion Sort #3

// Bubble Sort #4

// Shaker Sort #5

// Shell Sort #6

// Heap Sort #7

// Merge Sort #8

// Natural Merge Sort #9

// Quick Sort #10

// std:sort

// Radix Sort #11

// Counting Sort #12

// For Testing
int main(){
    int size = 100;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = rand();
    
    // Sorting Algorithm Go Here

    // Sorting Algorithm Go Here

    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
