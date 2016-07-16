//============================================================================
// Name        : Day21Generics.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printArray(vector<T> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}

int main() {
	vector<int> vInt { 1, 2, 3 };
	vector<string> vString { "Hello", "World" };

	printArray<int>(vInt);
	printArray<string>(vString);
	return 0;

}
