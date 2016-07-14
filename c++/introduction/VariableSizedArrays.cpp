#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	int** sequences = new int*[N];

	for (int i = 0; i < N; i++) {
		int sequenceLen;
		cin >> sequenceLen;
		int* sequence = new int[sequenceLen];

		for (int j = 0; j < sequenceLen; j++) {
			int element;
			cin >> element;
			sequence[j] = element;
		}

		*(sequences + i) = sequence;
	}

	for (int i = 0; i < Q; i++) {
		int sequenceIndex;
		int elementIndex;
		cin >> sequenceIndex >> elementIndex;

		cout << sequences[sequenceIndex][elementIndex] << endl;
	}

	for (int i = 0; i < N; i++) {
		delete[] sequences[i];
	}

	delete[] sequences;

	return 0;
}
