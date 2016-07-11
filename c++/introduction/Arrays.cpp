#include <vector>
#include <iostream>

using namespace std;

int main() {
    int count;
    cin >> count;

    vector<int> v;

    for (int i = 0; i < count; i++) {
        int n;
        cin >> n;

        v.push_back(n);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}