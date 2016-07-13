#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Stack {
private:
	vector<int> v;

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
};
