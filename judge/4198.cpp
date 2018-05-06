#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> weight;

int longest();

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		weight.push_back(x);
	}

	cout << longest() << endl;

	return 0;
}

int longest() {

	int dpUp[2000];
	int dpDown[2000];
	for (int i = N - 1; i >= 0; i--) {

		int maxUp = 0;
		int maxDown = 0;
		for (int j = i; j < N; j++) {
			if (weight[j] > weight[i] && dpUp[j] + 1 > maxUp) {
				maxUp = dpUp[j] + 1;
			}
			if (weight[j] < weight[i] && dpDown[j] + 1 > maxDown) {
				maxDown = dpDown[j] + 1;
			}
		}
		dpUp[i] = maxUp;
		dpDown[i] = maxDown;
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int x = dpUp[i] + dpDown[i] + 1;
		if (answer < x) answer = x;
	}

	return answer;
}
