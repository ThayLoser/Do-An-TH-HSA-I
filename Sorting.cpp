#include <iostream>
#include <random>
#include <time.h>
using namespace std;

// Selection Sort #1
void selectionSort(int *&a, int n){
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        swap(a[i], a[min]);
    }
}
// Insertion Sort #2
void insertionSort(int *&arr, int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// Binary Insertion Sort #3

// Bubble Sort #4
void bubbleSort(int *&arr, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 1; j < size - i; j++){
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
}
// Shaker Sort #5

// Shell Sort #6
void shellSort(int*& arr, int n){
    for (int gap = n / 2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++){
            int key = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > key) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = key;
        }
    }
}
// Heap Sort #7
void heapify(int *&arr, int size, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest]) largest = left;
    if (right < size && arr[right] > arr[largest]) largest = right;
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
void heapSort(int *&arr, int size){
    for (int i = size / 2 - 1; i >= 0; i--) heapify(arr, size, i);
    for (int i = size - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
// Merge Sort #8

// Natural Merge Sort #9
void naturalMerge(int *&arr, int left, int mid, int right){
    int n = right - left + 1;
    int *temp = new int[n];
    int i = left, j = mid + 1, d = 0;
    while (i <= mid && j <= right){
        if (arr[i] <= arr[j]) temp[d++] = arr[i++];
        else temp[d++] = arr[j++];
    }
    while (i <= mid) temp[d++] = arr[i++];
    while (j <= right) temp[d++] = arr[j++];
    for (int k = left; k <= right; k++) arr[k] = temp[k - left];
}
void naturalMergeSort(int *&arr, int n){
    if (n <= 1) return;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        int left = 0;
        while (left < n) {
            int mid = left;
            while (mid < n - 1 && arr[mid] <= arr[mid + 1]) mid++;
            if (mid == n - 1) break;
            int right = mid + 1;
            while (right < n - 1 && arr[right] <= arr[right + 1]) right++;
            naturalMerge(arr, left, mid, right);
            sorted = false;
            left = right + 1;
        }
    }
}
// Quick Sort #10
int partition(int *&a, int left, int right){
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++){
        if (a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}
void quickSort(int *&a, int left, int right){
    if (left < right){
        int pivotIndex = partition(a, left, right);
        quickSort(a, left, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, right);
    }
}
void quickSort(int*& a, int n){
    quickSort(a, 0, n - 1);
}
// std:sort
// sort(a, a + n);

// Radix Sort #11
int getMax(int *arr, int size){
    int max_arr = arr[0];
    for (int i = 0; i < size; i++)
        if (max_arr < arr[i]) max_arr = arr[i];
    return max_arr;
}
void counting(int *arr, int size, int exp){
    int *output = new int[size];
    int count[10] = {0};
    for (int i = 0; i < size; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < size; i++) arr[i] = output[i];
    delete[] output;
}
void RadixSort(int *arr, int size){
    int maxVal = getMax(arr, size);
    for (int i = 1; maxVal / i > 0; i *= 10) counting(arr, size, i);
}
// For Testing
int main() {
    srand(time(NULL));
    int size = 10;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = rand();

    // Sorting Algorithm Go Here

    // Sorting Algorithm Go Here

    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
