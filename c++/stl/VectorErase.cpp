#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; // number of vector elements
    int x; // position ef element to delete
    int a; // start index of range to delete
    int b; // end index of range to delete
    
    cin >> n;
    
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        v[i] = elem;
    }
    
    /* Erase an element at a position */
    cin >> x;
    v.erase(v.begin() + x - 1);
    
    /* Erase elements in a range */
    cin >> a >> b;
    v.erase(v.begin() + a - 1, v.begin() + b - 1);
    
    cout << v.size() << "\n";
    
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        
        cout << v[i];
    }
    
    cout << endl;
    
    return 0;
}