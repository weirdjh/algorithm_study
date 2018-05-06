#include <iostream>

using namespace std;

struct point {
	int r;
	int c;
	point() {};
	point(int r, int c) : r(r), c(c) {};
} P[100];

int head, tail;

int T;
int N, M, R, C, L;
int map[50][50];
bool isVisited[50][50];

int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0, 1, 0 };

int match[4][4] = {
	// 북쪽 방향과 match
	{1,2,5,6},
	// 동쪽 방향과 match
	{1,3,6,7},
	// 남쪽 방향과 match
	{1,2,4,7},
	// 서쪽 방향과 match
	{1,3,4,5}
};

int bfs();

int main(void) {
	cin >> T;

	for (int test = 1; test <= T; test++) {
		cin >> N >> M >> R >> C >> L;

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cin >> map[r][c];
				isVisited[r][c] = 0;
			}
		}
		cout << "#" << test << ' ' << bfs() << endl;
	}

	return 0;
}

int bfs() {
	
	int ret = 0;

	head = 0;
	tail = 0;
	P[tail++] = point(R, C);
	isVisited[R][C] = true;

	int passedTime = 0;

	while (head != tail) {
		
		int cnt = tail - head;
		passedTime++;
		if (passedTime > L) break;
		
		while (cnt--) {
			int row = P[head].r;
			int col = P[head].c;
			head++;

			ret++;

			int pipe = map[row][col];
			int r, c;
			int start, max, plus;

			if (pipe == 1) { start = 0; max = 4;	plus = 1; }
			else if (pipe == 2) { start = 0; max = 4; plus = 2; }
			else if (pipe == 3) { start = 1; max = 4; plus = 2; }
			else if (pipe == 4) { start = 0; max = 2; plus = 1; }
			else if (pipe == 5) { start = 1; max = 3; plus = 1; }
			else if (pipe == 6) { start = 2; max = 4; plus = 1; }
			else if (pipe == 7) {	start = 0; max = 4; plus = 3;	}

			for (int dir = start; dir < max; dir += plus) {
				r = row + dirY[dir];
				c = col + dirX[dir];

				if (r < 0 || r >= N || c < 0 || c >= M) continue;
				
				for (int k = 0; k < 4; k++) {
					if (map[r][c] == match[dir][k] && !isVisited[r][c]) {
						P[tail++] = point(r, c);
						isVisited[r][c] = true;
						break;
					}
				}
				
			}
		}

	}
	return ret;
}