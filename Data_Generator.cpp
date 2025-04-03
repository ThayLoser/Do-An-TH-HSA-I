#include <iostream>
#include <time.h>
using namespace std;

void GenerateRandomData(int *a, int n){
	srand(time(NULL));
	for (int i = 0; i < n; i++) a[i] = rand() % n + 0;
}

void GenerateSortedData(int *a, int n){
	for (int i = 0; i < n; i++) a[i] = i;
}

void GenerateReverseData(int *a, int n){
	for (int i = 0; i < n; i++) a[i] = n - 1 - i;
}

void GenerateNearlySortedData(int *a, int n){
	srand(time(NULL));
	for (int i = 0; i < n; i++) a[i] = i;
	for (int i = 0; i < n / 5; i++){
		int r1 = rand() % n + 0;
		int r2 = rand() % n + 0;
		swap(a[r1], a[r2]);
	}
}

void GenerateData(int *a, int n, int dataType){
	switch (dataType){
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
		printf("unknown data type!\n");
	}
}