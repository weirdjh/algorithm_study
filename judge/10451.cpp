#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int T;

int main(void) {

	cin >> T;

	deque<int> answer;
	while (T--) {
	
		int N;
		cin >> N;

		deque<int> arr[1001];
		int visited[1001];
		memset(visited, 0, sizeof(int) * 1001);

		for (int i = 1; i <= N; i++) {
			int x;
			cin >> x;
			arr[i].push_back(x);
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++) {

			if (visited[i]) continue;
			
			deque<int> que;
			que.push_back(i);
			visited[i] = 1;

			while (!que.empty()) {
				int x = que.front();
				que.pop_front();
				if (!arr[x].empty()) {
					int n = arr[x][0];
					if (!visited[n]) {
						visited[n] = 1;
						que.push_back(n);
					}
				}
				else break;

			}
			cnt++;
		}
		answer.push_back(cnt);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}