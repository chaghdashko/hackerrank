//============================================================================
// Name        : Day20_Sorting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

inline void swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int bubbleSort(vector<int>& a, int len) {
	int swapCount = 0;

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len - 1; ++j) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				swapCount++;
			}
		}
	}

	return swapCount;
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int swapCount = bubbleSort(a, n);

	cout << "Array is sorted in " << swapCount << " swaps." << endl;
	cout << "First Element: " << a[0] << endl;
	cout << "Last Element: " << a[n - 1] << endl;

	return 0;
}
