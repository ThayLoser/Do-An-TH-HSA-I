#include <iostream>
#include <random>
#include <time.h>
using namespace std;

// Selection Sort #1
void SelectionSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) min = j;
		}
		swap(a[i], a[min]);
	}
}

// Insertion Sort #2

// BinaryInsertion Sort #3

// Bubble Sort #4
void BubbleSort(int* arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 1; j < size - i; j++)
        {
            if(arr[j - 1] > arr[j])
                swap(arr[j-1], arr[j]);
        }
    }
}
// Shaker Sort #5

// Shell Sort #6

// Heap Sort #7
void heapify(int* arr, int size, int i) 
{
    int largest = i;       
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void HeapSort(int* arr, int size) 
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);  
        heapify(arr, i, 0);    
    }
}
// Merge Sort #8

// Natural Merge Sort #9

// Quick Sort #10

// std:sort

// Radix Sort #11
int getMax(int *arr, int size) 
{
    int max_arr = arr[0];
    for( int i = 0; i < size; i++)
    {
        if(max_arr < arr[i])
            max_arr = arr[i];
    }
    return max_arr;
}

void counting(int* arr, int size, int exp)
{
    int* output = new int[size];
    int count[10] = {0}; 

    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) 
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];

    delete[] output;
}

void RadixSort(int* arr, int size) 
{
    int maxVal = getMax(arr, size); 

    for (int i = 1; maxVal / i > 0; i *= 10)
        counting(arr, size, i);
}


// For Testing
int main(){
    srand(time(NULL));
    int size = 100;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = rand();
    
    // Sorting Algorithm Go Here
    
    // Sorting Algorithm Go Here

    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
