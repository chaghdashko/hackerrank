/*
 * main.cpp
 *
 *  Created on: 4 Tem 2016
 *      Author: cagdasko
 */

#include <iostream>

using namespace std;

int factorial(int n) {
	if (n == 1) {
		return n;
	} else {
		return n * factorial(n - 1);
	}
}

int main() {
	int x;
	cin >> x;
	int res = factorial(x);
	cout << res << endl;

	return 0;
}
