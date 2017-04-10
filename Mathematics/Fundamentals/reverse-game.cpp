// num elements	= 10
// query element	= 2
//
// original list		= 0 1 2 3 4 5 6 7 8 9 (0..(num elements - 1))
// after 1st reverse	= 9 8 7 6 5 4 3 2 1 0
// after 2nd reverse	= 9 0 1 2 3 4 5 6 7 8
// after 3rd reverse	= 9 0 8 7 6 5 4 3 2 1
// after 4th reverse	= 9 0 8 1 2 3 4 5 6 7
// after 5th reverse	= 9 0 8 1 7 6 5 4 3 2
// after 6th reverse	= 9 0 8 1 7 2 3 4 5 6
// after 7th reverse	= 9 0 8 1 7 2 6 5 4 3
// after 8th reverse	= 9 0 8 1 7 2 6 3 4 5
// after 9th reverse	= 9 0 8 1 7 2 6 3 5 4
// after 10th reverse	= 9 0 8 1 7 2 6 3 5 4
//
// index of query element 2 = 5

#include <list>
#include <vector>
#include <iterator>
#include <iostream>
#include <numeric>

using namespace std;

template<typename T>
void print_vector(vector<T>& v, const string& delim) {
	for (int i = 0; i < v.size(); i++) {
		if (i != 0)
			cout << delim;
		cout << v[i];
	}
	cout << endl;
}

vector<int> reverse(int n) {
	vector<int> v;

	int odd = 0;
	int even = n - 1;

	for (int j = 0; j < n; j++) {
		if (j % 2 == 0) {
			v.push_back(even--);
		} else {
			v.push_back(odd++);
		}
	}

	return v;
}

template<typename T>
T getIndexOf(const vector<T> v, T k) {
	for (int j = 0; j < v.size(); ++j) {
		if (v[j] == k) {
			return j;
		}
	}

	return -1;
}

int main() {
	int t, n, k;
	cin >> t;

	vector<int> results;

	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		vector<int> after_reverse = reverse(n);
		results.push_back(getIndexOf(after_reverse, k));
	}

	print_vector(results, "\n");

	return 0;
}