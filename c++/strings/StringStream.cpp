//============================================================================
// Name        : StringStream.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	vector<int> v;
	stringstream ss(str);

	while (ss.rdbuf()->in_avail()) {
		char c;
		int m;
		ss >> m;
		v.push_back(m);
		ss >> c; // For comma character
	}

	return v;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);

	for (size_t i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}
