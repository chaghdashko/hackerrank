#include <vector>
#include <iostream>

using namespace std;

int calc_min_draws(int num_of_pairs) {
    return num_of_pairs + 1;
}

int main() {
    int num_of_tests;
    cin >> num_of_tests;
    
    vector<int> results(num_of_tests);
    
    for (int i = 0; i < num_of_tests; i++) {
        int num_of_pairs;
        cin >> num_of_pairs;
        
        results[i] = calc_min_draws(num_of_pairs);
    }
    
    for (int i = 0; i < num_of_tests; i++)
        cout << results[i] << endl;
    
    return 0;
}
