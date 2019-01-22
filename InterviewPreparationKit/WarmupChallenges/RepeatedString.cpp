#include <bits/stdc++.h>

using namespace std;

long findCharCountInString(const string &s, const char &c)
{
    long numCharInString = 0;
    for (const char &i : s)
        if (i == c)
            numCharInString++;
    return numCharInString;
}

// Complete the repeatedString function below.
long repeatedString(string s, long n)
{
    long numAsInString = findCharCountInString(s, 'a');
    long numStrings = n / s.length();

    int rem = n % s.length();
    string sub = s.substr(0, rem);
    long numAsInRem = findCharCountInString(sub, 'a');

    return ((numAsInString * numStrings) + numAsInRem);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
