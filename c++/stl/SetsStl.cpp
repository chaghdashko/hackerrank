#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define QUERY_ADD 1
#define QUERY_DELETE 2
#define QUERY_SEARCH 3

struct Query {
    int type;
    int value;
};

int main()
{
    set<int> numberSet;
    set<int>::iterator itr;
    int q;
    cin >> q;

    vector<struct Query> queries(q);

    for (int i = 0; i < q; i++) {
        int type, value;
        cin >> type >> value;
        struct Query query = { type, value };
        queries[i] = query;
    }

    for (int i = 0; i < queries.size(); i++) {
        struct Query query = queries[i];

        switch (query.type) {
        case QUERY_ADD:
            numberSet.insert(query.value);
            break;
        case QUERY_DELETE:
            numberSet.erase(query.value);
            break;
        case QUERY_SEARCH:
            itr = numberSet.find(query.value);

            if (itr != numberSet.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;

            break;
        default:
            break;
        }
    }

    return 0;
}
