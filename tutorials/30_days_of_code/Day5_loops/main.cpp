/*
 * main.cpp
 *
 *  Created on: 5 Tem 2016
 *      Author: cagdasko
 */

#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= 10; i++) {
		cout << N << " x " << i << " = " << N * i << endl;
	}

	return 0;
}
