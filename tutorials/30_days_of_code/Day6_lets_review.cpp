/*
 * main.cpp
 *
 *  Created on: 5 Tem 2016
 *      Author: cagdasko
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int i;
    int n;
    unsigned int j;
    vector<string> inputs;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        string in;
        cin >> in;
        inputs.push_back(in);
    }

    for (auto it : inputs)
    {
        vector<char> odds;
        vector<char> evens;

        for (j = 0; j < it.length(); j++)
        {
            if (j % 2 == 0)
            {
                evens.push_back(it.at(j));
            }
            else
            {
                odds.push_back(it.at(j));
            }
        }

        stringstream ss_evens;

        for (j = 0; j < evens.size(); j++)
        {
            ss_evens << evens[j];
        }

        string s_evens = ss_evens.str();

        stringstream ss_odds;

        for (j = 0; j < odds.size(); j++)
        {
            ss_odds << odds[j];
        }

        string s_odds = ss_odds.str();

        cout << s_evens << " " << s_odds << endl;
    }

    return 0;
}

