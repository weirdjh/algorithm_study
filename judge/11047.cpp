#include <iostream>

using namespace std;

int N, K;
int coin[10];

int main(void) {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		while (coin[i] <= K) {
			K -= coin[i];
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}