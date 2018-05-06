#include <iostream>
#include <cstring>

#define MAX(a,b) (a) > (b) ? (a) : (b)

using namespace std;

int T;
int N, K;
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, -1, 0, 1 };

int map[8][8];
bool visited[8][8];

int hiking(int r, int c, bool cut, int value);

int main(void) {

	cin >> T;
	for (int test = 1; test <= T; test++) {

		cin >> N >> K;

		int top = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (top < map[i][j]) top = map[i][j];
			}
		}

		// 제일 높은 봉우리 좌표들 저장.
		pair<int, int> highest[5];
		int idx = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == top) highest[idx++] = { i,j };
			}
		}

		// 각 봉우리들로 부터 탐색
		int answer = 0;
		for (int i = 0; i < idx; i++) {

			memset(visited, 0, sizeof(visited));

			int row = highest[i].first;
			int col = highest[i].second;
			answer = MAX(answer, hiking(row, col, false, map[row][col]));

		}

		cout << "#" << test << ' ' << answer << endl;

	}

	return 0;
}

int hiking(int r, int c, bool cut, int value) {

	int ret = 0;

	// 이미 한 번 깎았을 때,

	for (int i = 0; i<4; i++) {
		int row = r + dirY[i];
		int col = c + dirX[i];

		if (row<0 || row >= N || col <0 || col >= N) continue;
		if (visited[row][col]) continue;

		// 한번 깍임.
		if (cut) {
			if (map[row][col] < value) {
				visited[row][col] = true;
				ret = MAX(ret, hiking(row, col, true, map[row][col]));
				visited[row][col] = false;
			}
		}

		else {
			if (value > map[row][col]) {
				visited[row][col] = true;
				ret = MAX(ret, hiking(row, col, false, map[row][col]));
				visited[row][col] = false;
			}
			else if (map[row][col] - K < value) {
				visited[row][col] = true;
				ret = MAX(ret, hiking(row, col, true, map[row][col] - K));
				visited[row][col] = false;
			}
		}
	}
	return 1 + ret;
}