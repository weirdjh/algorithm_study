#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N;

bool decrease(int a, int b) {
	return a > b;
}

int main(void) {

	cin >> N;

	deque<int> list;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		list.push_back(x);
	}

	int idx = N - 1;
	while (idx>0 && list[idx] > list[idx - 1]) idx--;

	if (idx == 0) cout << -1 << endl;
	else {
		int max = list[idx];
		int change = idx;
		for (int i = idx; i < N; i++) {
			if (max < list[i] && list[idx - 1] > list[i]) {
				max = list[i];
				change = i;
			}
		}
		list[change] = list[idx-1];
		list[idx-1] = max;
		sort(list.begin() + idx, list.end(), decrease);

		for (int i = 0; i < N; i++) {
			cout << list[i] << ' ';
		}cout << endl;
	}

	return 0;
}