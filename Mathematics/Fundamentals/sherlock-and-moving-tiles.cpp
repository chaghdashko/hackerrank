#include <cmath>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
	long L, S1, S2, Q;
	cin >> L >> S1 >> S2 >> Q;

	vector<long long> areas;

	for (long i = 0; i < Q; i++) {
		long long area;
		cin >> area;

		areas.push_back(area);
	}

	vector<long long>::iterator it;

	for (it = areas.begin(); it != areas.end(); ++it) {
		double line = sqrt(*it);
		double Xx = L - line;
		double t = Xx / (abs(S2 - S1) / sqrt(2));

		cout << fixed << setprecision(20) << t << endl;
	}

	return 0;
}