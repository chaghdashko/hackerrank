/*
 * dictionaries_and_maps.cpp
 *
 *  Created on: 4 Tem 2016
 *      Author: cagdasko
 */

#include <cmath>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	stringstream ss(s);
	int number_of_records;
	ss >> number_of_records;

	map<string, string> phone_book;

	for (int i = 0; i < number_of_records; i++) {
		getline(cin, s);
		istringstream is(s);
		vector<string> in;
		string elem;

		while (is >> elem)
			in.push_back(elem);

		phone_book[in[0]] = in[1];
	}

	vector<string> queries;

	while (getline(cin, s)) {
		if (s.empty())
			break;
		queries.push_back(s);
	}

	for (auto query : queries) {
		string res = phone_book[query];

		if (res.empty())
			cout << "Not found" << endl;
		else
			cout << query << "=" << res << endl;
	}

	return 0;
}

