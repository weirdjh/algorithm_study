#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> arr;

int main(void) {

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	int answer = 0;
	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << N-j-1)) {
				sum += arr[j];
			}
		}
		if (sum == S) {
			answer++;
		}
	}
	cout << answer << endl;

	return 0;
}