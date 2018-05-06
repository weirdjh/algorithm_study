#include <iostream>
#include <string>
#include <deque>

using namespace std;

int N, M;
int map[102][102];
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0, 1, 0 };

int main(void) {

	// input
	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		string s;
		cin >> s;
		for (int m = 1; m <= M; m++) {
			map[n][m] = s[m - 1] - '0';
		}
	}
	

	// bfs

	// coordinate && count
	deque < pair<int, int>> trace;

	trace.push_back({ 1,1 });

	while (!trace.empty()) {
		pair<int, int> point = trace.front();
		trace.pop_front();

		for (int i = 0; i < 4; i++) {
			int before = map[point.first][point.second];
			int X = point.second + dirX[i];
			int Y = point.first + dirY[i];
			
			if (map[Y][X] != 1) {
				continue;
			}
			else {
				trace.push_back({ Y,X });

				if (map[Y][X] == 1) {
					map[Y][X] = before + 1;
				}
			}
		}

	}

	cout << map[N][M] << endl;

	return 0;
}