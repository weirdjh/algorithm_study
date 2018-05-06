#include <iostream>
#include <algorithm>

using namespace std;

int N;
int lope[100001];

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> lope[i];
	}

	sort(lope, lope + N);

	int max = 0;
	for (int i = 0; i < N; i++) {
		if (max < lope[i] * (N-i)) max = lope[i] * (N-i);
	}
	cout << max << endl;

	return 0;
}