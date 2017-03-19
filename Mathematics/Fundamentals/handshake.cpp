#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int num_of_tests;
    cin >> num_of_tests;

    vector<int> num_of_handshakes(num_of_tests);

    for (int i = 0; i < num_of_tests; i++)
    {
        int num_of_members;
        cin >> num_of_members;

        switch (num_of_members)
        {
        case 1:
            num_of_handshakes[i] = 0;
            break;
        case 2:
            num_of_handshakes[i] = 1;
            break;
        default:
            num_of_handshakes[i] = (num_of_members * (num_of_members - 1)) / 2;
            break;
        }
    }

    for (int i = 0; i < num_of_tests; i++)
        cout << num_of_handshakes[i] << endl;

    return 0;
}
