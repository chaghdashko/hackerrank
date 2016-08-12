#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin >> q;
    vector<string> results(q);
    vector<int> indexes(q);
    for(int i=0;i<q;i++){
        int query;
        cin>>query;
        vector<int>::iterator low=lower_bound(v.begin(), v.end(), query);
        if(*low==query)
            results[i]="Yes";
        else
            results[i]="No";
        indexes[i]=low-v.begin()+1;
    }
    for(int i=0;i<q;i++)
        cout<<results[i]<<" "<<indexes[i]<<endl;
    return 0;
}

