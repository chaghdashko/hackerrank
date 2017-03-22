#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> roads(t);

    for (int i = 0; i < t; i++) {
        int n_towns;
        cin >> n_towns;

        unsigned long long n_roads = 1;

        for (int j = 0; j < n_towns - 1; j++) {
            int n;
            cin >> n;

            n_roads = ((long long)n_roads * n) % 1234567;
            //cout << "n_roads " << j + 1 << " = " << n_roads << endl;
        }

        roads[i] = n_roads;
    }

    for (int i = 0; i < t; i++) {
        cout << roads[i] << endl;
    }

    return 0;
}