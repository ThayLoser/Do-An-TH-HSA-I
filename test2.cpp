#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <ctime>

// Chỉ gọi srand(time(NULL)) một lần trong chương trình
void InitializeRandom() {
    srand(time(NULL));
}

// Sinh dữ liệu ngẫu nhiên
void GenerateRandomData(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % n;
    }
}

// Sinh dữ liệu sắp xếp tăng dần
void GenerateSortedData(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
}

// Sinh dữ liệu sắp xếp giảm dần
void GenerateReverseData(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = n - 1 - i;
    }
}

// Sinh dữ liệu gần như sắp xếp (hoán đổi ngẫu nhiên một số phần tử)
void GenerateNearlySortedData(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    for (int i = 0; i < n / 5; i++) {
        int r1 = rand() % n;
        int r2 = rand() % n;
        std::swap(a[r1], a[r2]);
    }
}

// Hàm tổng hợp để sinh dữ liệu dựa vào kiểu
void GenerateData(int* a, int n, int dataType) {
    switch (dataType) {
        case 0: GenerateRandomData(a, n); break;
        case 1: GenerateSortedData(a, n); break;
        case 2: GenerateReverseData(a, n); break;
        case 3: GenerateNearlySortedData(a, n); break;
        default: std::cout << "Unknown data type!\n"; break;
    }
}

// Thuật toán Bubble Sort
void BubbleSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

// Đo thời gian thực thi bằng chrono
template <typename Func, typename... Args>
double MeasureExecutionTime(Func func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / 1000.0;  // Chuyển đổi sang milliseconds
}

// Đo thời gian bằng cách thủ công
void DemoManualTiming(int* a, int size) {
    int* temp = new int[size];  // Tạo bản sao
    std::copy(a, a + size, temp);

    auto start = std::chrono::high_resolution_clock::now();
    BubbleSort(temp, size);
    auto end = std::chrono::high_resolution_clock::now();

    delete[] temp;  // Giải phóng bộ nhớ

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Manual timing: Bubble sort took " << duration.count() << " milliseconds\n";
}

// Đo thời gian trung bình của thuật toán
double MeasureAverageTime(int* a, int runs, int size) {
    double totalTime = 0.0;
    for (int i = 0; i < runs; i++) {
        int* temp = new int[size];  // Tạo bản sao
        std::copy(a, a + size, temp);

        auto start = std::chrono::high_resolution_clock::now();
        BubbleSort(temp, size);
        auto end = std::chrono::high_resolution_clock::now();

        delete[] temp;  // Giải phóng bộ nhớ

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += duration.count();
    }
    return (totalTime / runs) / 1000.0;  // Chuyển đổi sang milliseconds
}

int main() {
    InitializeRandom();  // Khởi tạo bộ sinh số ngẫu nhiên

    int sizeArray[] = {10000, 20000, 40000, 60000, 80000, 100000};
    int n = sizeof(sizeArray) / sizeof(sizeArray[0]);

    int dataType;
    std::cout << "Input data type (0: Random, 1: Sorted, 2: Reverse, 3: Nearly Sorted): ";
    std::cin >> dataType;

    for (int i = 0; i < 2; i++) {
        int size = sizeArray[i];
        int* originalArray = new int[size]; // Lưu trữ dữ liệu ban đầu
GenerateData(originalArray, size, dataType);

// Tạo bản sao trước khi chạy đo thời gian
int* a = new int[size];

// Đo thời gian với MeasureExecutionTime
std::copy(originalArray, originalArray + size, a); 
double sortingTime = MeasureExecutionTime(BubbleSort, a, size);
std::cout << "Bubble sort took " << sortingTime << " milliseconds for size " << size << "\n";

// Đo thời gian bằng phương pháp thủ công
std::copy(originalArray, originalArray + size, a);
DemoManualTiming(a, size);

// Đo thời gian trung bình
std::copy(originalArray, originalArray + size, a);
double avgTime = MeasureAverageTime(a, 5, size);
std::cout << "Average algorithm sort time over 5 runs: " << avgTime << " milliseconds\n";

// Giải phóng bộ nhớ
delete[] a;
delete[] originalArray;

    }
    return 0;
}
