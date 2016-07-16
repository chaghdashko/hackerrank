//============================================================================
// Name        : VirtualFunctions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Person {
public:
	string name;
	int age;
	int id_;

	virtual void getdata()=0;
	virtual void putdata()=0;
};

class Student: public Person {
public:
	int marks[6];
	static int id;

	void getdata() {
		cin >> name >> age;

		for (int i = 0; i < 6; i++)
			cin >> marks[i];

		id++;
		id_ = id;
	}

	void putdata() {
		int sum = 0;

		for (int i = 0; i < 6; i++)
			sum += marks[i];

		cout << name << " " << age << " " << sum << " " << id_ << endl;
	}
};

int Student::id = 0;

class Professor: public Person {
public:
	int publications;
	static int id;

	void getdata() {
		cin >> name >> age >> publications;
		id++;
		id_ = id;
	}

	void putdata() {
		cout << name << " " << age << " " << publications << " " << id_ << endl;
	}
};

int Professor::id = 0;

int main() {

	int n, val;
	cin >> n; //The number of objects that is going to be created.

	Person * per[n];

	for (int i = 0; i < n; i++) {
		cin >> val;

		if (val == 1)
			per[i] = new Professor; // If val is 1 current object is of type Professor
		else
			per[i] = new Student;  // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.
	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;

}

