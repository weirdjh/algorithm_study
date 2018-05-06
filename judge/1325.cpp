#include <iostream>
#include <deque>

using namespace std;

int N, M;
deque<int> hack[10001];
int dist[10001];

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> end >> start;
		hack[start].push_back(end);
	}

	deque<int> que;
	int max = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		int visited[10001] = {};

		que.push_back(i);
		visited[i] = 1;
		cnt++;

		while (!que.empty()) {
			int x = que.front();
			que.pop_front();
			
			for (int k = 0; k < hack[x].size(); k++) {
				if (!visited[hack[x][k]]) {
					visited[hack[x][k]] = 1;
					que.push_back(hack[x][k]);
					cnt++;
				}
			}
		}
		dist[i] = cnt;
		if (cnt > max) max = cnt;
	}

	for (int i = 1; i <= N; i++) {
		if (max == dist[i]) {
			cout << i << ' ';
		}
	}cout << endl;


	return 0;
}