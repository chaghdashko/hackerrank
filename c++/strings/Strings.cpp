//============================================================================
// Name        : Strings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	cout << a.size() << " " << b.size() << endl;
	cout << a + b << endl;

	char tmp = a[0];
	a[0] = b[0];
	b[0] = tmp;
	cout << a << " " << b << endl;

	return 0;
}
