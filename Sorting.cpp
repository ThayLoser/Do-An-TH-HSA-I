#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

// ** Nhóm Hàm Sắp Xếp **
// -----------------------------------------------------
// Group 1
// -----------------------------------------------------
// Selection Sort #1
void selectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
    }
}
// Insertion Sort #2
void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// Binary Insertion Sort #3
int binarySearch(int *arr, int left, int right, int x)
{
    if (left > right)
        return left;
    int mid = left + (right - left) / 2;
    if (*(arr + mid) == x)
        return mid + 1;
    else if (*(arr + mid) > x)
        return binarySearch(arr, left, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, right, x);
}
void binaryInsertionSort(int *arr, int size)
{
    int i, j, loc, selection;
    for (i = 1; i < size; i++)
    {
        selection = *(arr + i);
        j = i - 1;
        loc = binarySearch(arr, 0, j, selection);
        while (j >= loc)
        {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = selection;
    }
}
// Bubble Sort #4
void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
}
// Shaker Sort #5
void shakerSort(int *arr, int size)
{
    int left = 0, right = size - 1, k = size - 1, i;
    while (left < right)
    {
        for (i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        left = k;
        for (i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        right = k;
    }
}
// Shell Sort #6
void shellSort(int *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int key = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = key;
        }
    }
}
// ------------------------------------------------------
// Group 2
// -----------------------------------------------------
// Heap Sort #7
void heapify(int *arr, int size, int i)
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
void heapSort(int *arr, int size)
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
void merge(int *a, int left, int mid, int right)
{
    int p1 = left, p2 = mid + 1, d = 0;
    vector<int> tmpArr(right - left + 1);
        while (p1 <= mid && p2 <= right)
    {
        if (a[p1] < a[p2])
            tmpArr[d++] = a[p1++];
        else
            tmpArr[d++] = a[p2++];
    }
    while (p1 <= mid)
        tmpArr[d++] = a[p1++];
    while (p2 <= right)
        tmpArr[d++] = a[p2++];
    int index = left;
    for (int i = 0; i < d; i++)
        a[index++] = tmpArr[i];
}
void mergeSort(int *a, int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
void mergeSort(int *a, int n)
{
    mergeSort(a, 0, n - 1);
}
// Natural Merge Sort #9
void naturalMerge(int *arr, int left, int mid, int right)
{
    int n = right - left + 1;
    int *temp = new int[n];
    int i = left, j = mid + 1, d = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[d++] = arr[i++];
        else
            temp[d++] = arr[j++];
    }
    while (i <= mid)
        temp[d++] = arr[i++];
    while (j <= right)
        temp[d++] = arr[j++];
    for (int k = left; k <= right; k++)
        arr[k] = temp[k - left];
    delete[] temp;
}
void naturalMergeSort(int *arr, int n)
{
    if (n <= 1)
        return;
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        int left = 0;
        while (left < n)
        {
            int mid = left;
            while (mid < n - 1 && arr[mid] <= arr[mid + 1])
                mid++;
            if (mid == n - 1)
                break;
            int right = mid + 1;
            while (right < n - 1 && arr[right] <= arr[right + 1])
                right++;
            naturalMerge(arr, left, mid, right);
            sorted = false;
            left = right + 1;
        }
    }
}
// Quick Sort #10
int medianOfThree(int *a, int left, int right)
{
    int mid = left + (right - left) / 2;

    // Sắp xếp 3 phần tử: left, mid, right
    if (a[left] > a[mid])
        swap(a[left], a[mid]);
    if (a[left] > a[right])
        swap(a[left], a[right]);
    if (a[mid] > a[right])
        swap(a[mid], a[right]);

    // Trả về vị trí của phần tử ở giữa
    return mid;
}
int partition(int *a, int left, int right)
{
    // Chọn pivot bằng median of three
    int pivotIndex = medianOfThree(a, left, right);
    int pivot = a[pivotIndex];

    // Đưa pivot về cuối mảng
    swap(a[pivotIndex], a[right]);

    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}
void quickSortHelper(int *a, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(a, left, right);
        quickSortHelper(a, left, pivotIndex - 1);
        quickSortHelper(a, pivotIndex + 1, right);
    }
}
void quickSort(int *a, int n)
{
    quickSortHelper(a, 0, n - 1);
}
// std:sort
void StdSort(int *arr, int size)
{
    sort(arr, arr + size);
}
// ------------------------------------------------------
// Group 3
// -----------------------------------------------------
// Radix Sort #11
int getMax(int *arr, int size)
{
    int max_arr = arr[0];
    for (int i = 0; i < size; i++)
        if (max_arr < arr[i])
            max_arr = arr[i];
    return max_arr;
}
void counting(int *arr, int size, int exp)
{
    int *output = new int[size];
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
void radixSort(int *arr, int size)
{
    int maxVal = getMax(arr, size);
    for (int i = 1; maxVal / i > 0; i *= 10)
        counting(arr, size, i);
}
// Counting Sort #12
void countingSort(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    int i;
    vector<int> count(max + 1, 0);
    for (i = 0; i < size; i++)
        count[arr[i]]++;
    i = 0;
    for (int j = 0; j <= max; j++)
    {
        while (count[j] > 0)
        {
            arr[i] = j;
            count[j]--;
            i++;
        }
    }
}
// -----------------------------------------------------
// ** Nhóm Hàm Khởi Tạo Dữ Liệu **
// -----------------------------------------------------
// Sinh dữ liệu ngẫu nhiên
void GenerateRandomData(int *a, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}
// Sinh dữ liệu sắp xếp tăng dần
void GenerateSortedData(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}
// Sinh dữ liệu sắp xếp giảm dần
void GenerateReverseData(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}
// Sinh dữ liệu gần như sắp xếp
void GenerateNearlySortedData(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < n / 5; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        swap(a[r1], a[r2]);
    }
}
// Hàm tổng hợp để sinh dữ liệu dựa vào kiểu
void GenerateData(int *a, int n, int dataType)
{
    switch (dataType)
    {
    case 0:
        GenerateRandomData(a, n);
        break;
    case 1:
        GenerateSortedData(a, n);
        break;
    case 2:
        GenerateReverseData(a, n);
        break;
    case 3:
        GenerateNearlySortedData(a, n);
        break;
    default:
        cout << "Unknown data type!\n";
        break;
    }
}
// -----------------------------------------------------
// ** Nhóm Hàm Khởi Tạo Bảng Kết Quả **
// -----------------------------------------------------
// Hàm đo thời gian thực hiện của một thuật toán sắp xếp
double measureSortTime(void (*sortFunc)(int *, int), int *arr, int size)
{
    int *temp = new int[size];
    copy(arr, arr + size, temp);
    auto start = chrono::high_resolution_clock::now();
    sortFunc(temp, size);
    auto end = chrono::high_resolution_clock::now();
    delete[] temp;
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    return static_cast<double>(duration) / 1000.0;
}
// Hàm in bảng kết quả
void printTable(const char *title, int *sizes, int numSizes, void (*sortFuncs[])(int *, int),
                const char *sortNames[], int numSorts, int dataType)
{
    // Calculate maximum width for algorithm names
    size_t maxAlgoWidth = 0;
    for (int i = 0; i < numSorts; i++) {
        maxAlgoWidth = max(maxAlgoWidth, strlen(sortNames[i]));
    }

    // Print title and header
    cout << "\n" << title << "\n\n";
    
    // Print size headers with fixed width
    cout << setfill(' ') << left << setw(maxAlgoWidth + 2) << "Size";
    for (int i = 0; i < numSizes; i++) {
        cout << right << setw(12) << sizes[i];
    }
    cout << "\n";

    // Print separator line
    cout << string(maxAlgoWidth + 2 + numSizes * 12, '-') << "\n";

    // Print algorithm results
    for (int i = 0; i < numSorts; i++) {
        cout << left << setw(maxAlgoWidth + 2) << sortNames[i];
        for (int j = 0; j < numSizes; j++) {
            int *arr = new int[sizes[j]];
            GenerateData(arr, sizes[j], dataType);
            double time = measureSortTime(sortFuncs[i], arr, sizes[j]);
            cout << fixed << setprecision(3) << right << setw(12) << time;
            delete[] arr;
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    // Các kích thước mảng
    int exp1Size[10] = {10000, 20000, 40000, 60000, 80000, 100000, 120000, 140000, 160000, 200000};
    int exp2Size[10] = {1000000, 2000000, 4000000, 6000000, 8000000, 10000000,
                        12000000, 14000000, 16000000, 20000000};
    // Danh sách các hàm sắp xếp cho thí nghệm 1
    void (*sortFunctions1[])(int *, int) = {
        selectionSort,
        insertionSort,
        binaryInsertionSort,
        bubbleSort,
        shakerSort,
        shellSort,
        heapSort,
        mergeSort,
        naturalMergeSort,
        quickSort,
        radixSort,
        countingSort,
        StdSort};
    // Tên các thuật toán sắp xếp cho thí nghệm 1
    const char *sortNames1[] = {
        "Selection Sort",
        "Insertion Sort",
        "BiInsertion",
        "Bubble Sort",
        "Shaker Sort",
        "Shell Sort",
        "Heap Sort",
        "Merge Sort",
        "Natural Merge",
        "Quick Sort",
        "Radix Sort",
        "Counting Sort",
        "std::sort"};
    // Danh sách các hàm sắp xếp cho thí nghệm 2
    void (*sortFunctions2[])(int *, int) = {
        shellSort,
        heapSort,
        mergeSort,
        naturalMergeSort,
        quickSort,
        radixSort,
        countingSort,
        StdSort};
    // Tên các thuật toán sắp xếp cho thí nghệm 2
    const char *sortNames2[] = {
        "Shell Sort",
        "Heap Sort",
        "Merge Sort",
        "Natural Merge",
        "Quick Sort",
        "Radix Sort",
        "Counting Sort",
        "std::sort"};
    // Số lượng hàm sắp xếp và kích thước mảng
    int numSorts1 = sizeof(sortFunctions1) / sizeof(sortFunctions1[0]);
    int numSorts2 = sizeof(sortFunctions2) / sizeof(sortFunctions2[0]);
    int numSizes1 = sizeof(exp1Size) / sizeof(exp1Size[0]);
    int numSizes2 = sizeof(exp2Size) / sizeof(exp2Size[0]);
    // Bảng 1: Mảng gần như đã sắp xếp (thí nghiệm 1)
    printTable("Nearly Sorted Array Performance (Experiment 1):", exp1Size, numSizes1,
               sortFunctions1, sortNames1, numSorts1, 3);
    // Bảng 2: Mảng sắp xếp ngược (thí nghiệm 1)
    printTable("Reverse Sorted Array Performance (Experiment 1):", exp1Size, numSizes1,
               sortFunctions1, sortNames1, numSorts1, 2);
    // Bảng 3: Mảng ngẫu nhiên (thí nghiệm 1)
    printTable("Random Array Performance (Experiment 1):", exp1Size, numSizes1,
                sortFunctions1, sortNames1, numSorts1, 0);
    // Bảng 4: Mảng sắp xếp tăng dần (thí nghiệm 1)
    printTable("Sorted Array Performance (Experiment 1):", exp1Size, numSizes1,
                sortFunctions1, sortNames1, numSorts1, 1);
    // Bảng 5: Mảng gần như đã sắp xếp (thí nghiệm 2)
    printTable("Nearly Sorted Array Performance (Experiment 2):", exp2Size, numSizes2,
               sortFunctions2, sortNames2, numSorts2, 3);
    // Bảng 6: Mảng sắp xếp ngược (thí nghiệm 2)
    printTable("Reverse Sorted Array Performance (Experiment 2):", exp2Size, numSizes2,
               sortFunctions2, sortNames2, numSorts2, 2);
    // Bảng 7: Mảng ngẫu nhiên (thí nghiệm 2)
    printTable("Random Array Performance (Experiment 2):", exp2Size, numSizes2,
               sortFunctions2, sortNames2, numSorts2, 0);
    // Bảng 8: Mảng sắp xếp tăng dần (thí nghiệm 2)
    printTable("Sorted Array Performance (Experiment 2):", exp2Size, numSizes2,
               sortFunctions2, sortNames2, numSorts2, 1);

    return 0;
}
