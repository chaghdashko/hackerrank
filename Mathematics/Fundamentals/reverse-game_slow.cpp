#include <list>
#include <vector>
#include <iterator>
#include <iostream>
#include <numeric>

using namespace std;

static inline list<int> generateList(int numElements, int startIndex) {
    list<int> li(numElements);
    iota(li.begin(), li.end(), startIndex);
    return li;
}

template<typename T>
void print_vector(vector<T>& v, const string& delim) {
    for (int i = 0; i < v.size(); i++) {
        if (i != 0)
            cout << delim;
        cout << v[i];
    }
    cout << endl;
}

int main() {
    int t, n, k;
    cin >> t;
    
    vector<int> results;
    
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        auto li = generateList(n, 0);
        vector<int> after_reverse;
        
        for (int j = 0; j < n; j++) {
            li.reverse();
            after_reverse.push_back(li.front());
            li.pop_front();
        }
        
        for(int j = 0; j < after_reverse.size(); ++j) {
            if (after_reverse[j] == k) {
                results.push_back(j);
                break;
            }
        }
    }
    
    print_vector(results, "\n");
    
    return 0;
}