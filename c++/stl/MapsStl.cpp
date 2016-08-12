#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>

#define QUERY_ADD 1
#define QUERY_ERASE 2
#define QUERY_PRINT 3

using namespace std;

int main()
{
    int queryCount;
    int queryType;
    string studentName;
    int marks;

    map<string, int> grades;
    map<string, int>::iterator itr;

    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        cin >> queryType >> studentName;
        itr = grades.find(studentName);

        if (queryType == QUERY_ADD) {
            cin >> marks;

            if (itr != grades.end()) {
                marks += itr->second;
                grades.erase(studentName);
            }

            grades.insert(make_pair(studentName, marks));
        }
        else if (queryType == QUERY_ERASE) {
            grades.erase(studentName);
        }
        else if (queryType == QUERY_PRINT) {
            if (itr != grades.end()) {
                cout << itr->second << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else {
            // Do nothing.
        }
    }
    return 0;
}
