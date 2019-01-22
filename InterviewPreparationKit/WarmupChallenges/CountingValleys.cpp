#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s)
{
    int valleyCount = 0;
    int prev = 0;
    int current = 0;

    for (auto i : s)
    {
        if (i == 'D')
        {
            if (prev == 0)
            {
                valleyCount++;
            }

            prev -= 1;
        }
        else
        {
            prev += 1;
        }
    }

    return valleyCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
