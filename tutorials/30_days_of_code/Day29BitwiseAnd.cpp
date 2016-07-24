#include <vector>
#include <iostream>

using namespace std;

int main() {
    int t, n, k;
    int max = 0;
    int val = 0;
    
    cin >> t;
    
    vector<int> maxValues(t);
    
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        
        for (int j = 1; j <= (n - 1); j++) {
            for (int _j = (j + 1); _j <= n; _j++) {
                val = j & _j;
                
                if ((val > max) && (val < k)) {
                    max = val;
                }
            }
        }
        
        maxValues[i] = max;
        max = 0;
    }
    
    for (size_t i = 0; i < maxValues.size(); i++) {
        cout << maxValues[i] << "\n";
    }
    
    return 0;
}