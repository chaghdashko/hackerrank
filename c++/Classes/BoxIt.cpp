#include <iostream>
#include <ostream>

using namespace std;

#pragma once
class Box {
private:
	int l, b, h;

public:
	Box() {
		l = 0;
		b = 0;
		h = 0;
	}

	Box(int length, int breadth, int height) {
		this->l = length;
		this->b = breadth;
		this->h = height;
	}

	Box(const Box& box) {
		l = box.l;
		b = box.b;
		h = box.h;
	}

	int getLength() { return this->l; }

	int getBreadth() { return this->b; }

	int getHeight() { return this->h; }

	long long CalculateVolume() { return (long long) l * b * h; }

	bool operator<(Box &other) {
		if (l < other.getLength()) {
			return true;
		}

		if (l == other.getLength() && b < other.getBreadth()) {
			return true;
		}

		if (h < other.getHeight() && l == other.getLength() &&
			b == other.getBreadth()) {
			return true;
		}

		return false;
	}

	friend std::ostream& operator<<(std::ostream &out, Box &box) {
		out << box.l << " " << box.b << " " << box.h;
		return out;
	}
};

void check2() {
	int n;
	cin >> n;

	Box temp;

	for (int i = 0; i < n; i++) {
		int type;
		cin >> type;

		if (type == 1) {
			cout << temp << endl;
		}

		if (type == 2) {
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}

		if (type == 3) {
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);

			if (NewBox < temp) {
				cout << "Lesser\n";
			}
			else {
				cout << "Greater\n";
			}
		}

		if (type == 4) {
			cout << temp.CalculateVolume() << endl;
		}

		if (type == 5) {
			Box NewBox(temp);
			cout << NewBox << endl;
		}
	}
}

int main() { check2(); }