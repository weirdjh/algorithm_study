#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int T;
int timeB[1001];

int calculate(int n, deque<int> b[1000], int bt[1001]);

int main(void) {

	cin >> T;

	deque<int> answer;
	while (T--) {

		int N, K;

		cin >> N >> K;
		memset(timeB, 0, sizeof(int) * 1001);

		int buildTime[1001];
		for (int i = 1; i <= N; i++) {
			cin >> buildTime[i];
		}

		deque<int> buildOrder[1001];
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;

			// build a before b
			buildOrder[b].push_back(a);
		}

		int goal; 
		cin >> goal;

		answer.push_back(calculate(goal, buildOrder, buildTime));

	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}

int calculate(int n, deque<int> b[1000], int bt[1001]) {

	if (b[n].empty()) return timeB[n] = bt[n];

	if (timeB[n]) return timeB[n];
	else {
		int max = 0;
		for (int i = 0; i < b[n].size(); i++) {
			int t = calculate(b[n][i], b, bt);
			if (t > max) {
				max = t;
			}
		}
		return timeB[n] = max + bt[n];
	}
}