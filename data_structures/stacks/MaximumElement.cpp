#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Stack {
private:
	vector<int> v;
	int stack_max = 0;

public:
	void push(int data) {
		v.push_back(data);
		if (data > stack_max) stack_max = data;
	}

	int pop() {
		int val = v[v.size() - 1];
		v.erase(v.begin() + v.size() - 1);

		if (val == stack_max)
			if (v.size() > 0)
				stack_max = *max_element(v.begin(), v.end());
			else
				stack_max = 0;

		return val;
	}

	int peek() { return *v.end(); }

	int max() { return stack_max; }
};

int main() {
	Stack stack;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int query, param;
		cin >> query;

		if (query == 1) {
			cin >> param;
			stack.push(param);
		}
		else if (query == 2) {
			int val = stack.pop();
		}
		else if (query == 3) {
			cout << stack.max() << endl;
		}
	}

	return 0;
}
