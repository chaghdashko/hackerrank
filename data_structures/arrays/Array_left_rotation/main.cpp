/*
 * main.cpp
 *
 *  Created on: 5 Tem 2016
 *      Author: cagdasko
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;

	// read first line: "N(int) r(int)",
	// where    N -> array element count
	// and      r -> left rotate amount
	getline(cin, s);
	istringstream is(s);
	vector<int> input;
	int x;
	while (is >> x)
		input.push_back(x);

	int sz_elem = input[0];
	int rot_num = input[1];

	// read int array
	vector<int> array;
	getline(cin, s);
	istringstream is2(s);
	int i = 0;
	while (is2 >> x) {
		if (i != sz_elem)
			array.push_back(x);
		else
			break;

		i++;
	}

	vector<int> tmp;

	for (i = 0; i < rot_num; i++) {
		tmp.push_back(array[i]);
		array[i] = 0;
	}

	for (i = rot_num; i < array.size(); i++) {
		array[i - rot_num] = array[i];
		array[i] = 0;
	}

	for (i = 0; i < rot_num; i++) {
		array[sz_elem - rot_num + i] = tmp[i];
	}

	for (auto x : array)
		cout << x << " ";

	cout << endl;

	return 0;
}

