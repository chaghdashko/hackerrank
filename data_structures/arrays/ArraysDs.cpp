/*
 * main.cpp
 *
 *  Created on: 5 Tem 2016
 *      Author: cagdasko
 */

#include <vector>
#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
       cin >> arr[i];
    }

    for(int i = n - 1; i >= 0 ; i--) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}



