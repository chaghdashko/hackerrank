#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
private:
	vector<char> v;
public:
	void push(char data) {
		v.push_back(data);
	}

	char pop() {
		int val = v[v.size() - 1];
		v.erase(v.begin() + v.size() - 1);
		return val;
	}
};

class Queue {
private:
	vector<char> v;
public:
	void push(char data) {
		v.push_back(data);
	}

	char pop() {
		int val = *v.begin();
		v.erase(v.begin());
		return val;
	}
};

class Solution {
private:
	Stack stack;
	Queue queue;
public:
	void pushCharacter(char ch) { stack.push(ch); }
	char popCharacter() { return stack.pop(); }
	void enqueueCharacter(char ch) { queue.push(ch); }
	char dequeueCharacter() { return queue.pop(); }
};

int main() {
	// read the string s.
	string s;
	getline(cin, s);

	// create the Solution class object p.
	Solution obj;

	// push/enqueue all the characters of string s to stack.
	for (int i = 0; i < s.length(); i++) {
		obj.pushCharacter(s[i]);
		obj.enqueueCharacter(s[i]);
	}

	bool isPalindrome = true;

	// pop the top character from stack.
	// dequeue the first character from queue.
	// compare both the characters.
	for (int i = 0; i < s.length() / 2; i++) {
		if (obj.popCharacter() != obj.dequeueCharacter()) {
			isPalindrome = false;

			break;
		}
	}

	// finally print whether string s is palindrome or not.
	if (isPalindrome) {
		cout << "The word, " << s << ", is a palindrome.";
	}
	else {
		cout << "The word, " << s << ", is not a palindrome.";
	}

	return 0;
}
