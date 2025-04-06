#include <iostream>
#include <random>
#include <time.h>
using namespace std;

// Selection Sort #1
void selectionSort(int* a, int n){
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        swap(a[i], a[min]);
    }
}
// Insertion Sort #2
void insertionSort(int* arr, int n){
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
int binarySearch(int* arr, int left, int right, int x){
    if (left > right) return left;
    int mid = left + (right - left) / 2;
    if (*(arr + mid) == x) return mid + 1;
    else if (*(arr + mid) > x) return binarySearch(arr, left, mid - 1, x);
    else return binarySearch(arr, mid + 1, right, x);
}
void binaryInsertionSort(int *arr, int size){
    int i, j, loc, selection; 
    for (i = 1; i < size; i++) {
        selection = *(arr + i);
        j = i - 1;
        loc = binarySearch(arr, 0, j, selection);
        while (j >= loc) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = selection;
    }
}
// Bubble Sort #4
void bubbleSort(int* arr, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 1; j < size - i; j++){
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
}
// Shaker Sort #5
void shakerSort(int* arr, int size) {
    int left = 0, right = size - 1, k = size - 1, i;
    while (left < right) {
        for (i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        left = k;
        for (i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        right = k;
    }
}
// Shell Sort #6
void shellSort(int* arr, int n){
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
void heapify(int* arr, int size, int i){
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
void heapSort(int* arr, int size){
    for (int i = size / 2 - 1; i >= 0; i--) heapify(arr, size, i);
    for (int i = size - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
// Merge Sort #8
void merge(int* a, int left, int mid, int right) {
	int p1 = left, p2 = mid + 1, d = 0;
	int* tmpArr = new int[right - left + 1];
	while (p1 <= mid && p2 <= right){
		if (a[p1] < a[p2]) tmpArr[d++] = a[p1++];
		else tmpArr[d++] = a[p2++];
	}
	while (p1 <= mid) tmpArr[d++] = a[p1++];
	while (p2 <= right) tmpArr[d++] = a[p2++];
    int index = left;
	for (int i = 0; i < d; i++) a[index++] = tmpArr[i];
	delete[] tmpArr;
}
void mergeSort(int* a, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}
void mergeSort(int* a, int n){
    mergeSort(a, 0, n - 1);
}
// Natural Merge Sort #9
void naturalMerge(int* arr, int left, int mid, int right){
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
void naturalMergeSort(int* arr, int n){
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
int medianOfThree(int* arr, int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid]) swap(arr[left], arr[mid]);
    if (arr[left] > arr[right]) swap(arr[left], arr[right]);
    if (arr[mid] > arr[right]) swap(arr[mid], arr[right]);
    swap(arr[mid], arr[right]); 
    return arr[right];
}
int partition(int* a, int left, int right) {
    int pivot = medianOfThree(a, left, right);
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}
void quickSortRecur(int* a, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(a, left, right);
        quickSortRecur(a, left, pivotIndex - 1);
        quickSortRecur(a, pivotIndex + 1, right);
    }
}
void quickSort(int* a, int n) {
    quickSortRecur(a, 0, n - 1);
}
// std:sort
// sort(a, a + n);

// Radix Sort #11
int getMax(int* arr, int size){
    int max_arr = arr[0];
    for (int i = 0; i < size; i++)
        if (max_arr < arr[i]) max_arr = arr[i];
    return max_arr;
}
void counting(int* arr, int size, int exp){
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
void radixSort(int* arr, int size){
    int maxVal = getMax(arr, size);
    for (int i = 1; maxVal / i > 0; i *= 10) counting(arr, size, i);
}
// Counting Sort #12
void countingSort(int* arr, int size){
    int max = arr[0];
    for (int i = 0; i < size; i++){
        if (max < arr[i])
            max = arr[i];
    }
    int i;
    vector<int> count(max + 1, 0);
    for (i = 0; i < size; i++)
        count[arr[i]]++;
    i = 0;
    for (int j = 0; j <= max; j++){
        while (count[j] > 0) {
            arr[i] = j;
            count[j]--;
            i++;
        }
    }
} 
// For Testing
int main() {
    srand(time(NULL));
    int size = 10;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = rand();

    // Sorting Algorithm Go Here
    insertionSort(arr, size);
    // Sorting Algorithm Go Here

    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
