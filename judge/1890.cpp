#include <iostream>
#include <cstring>

#define ll long long

using namespace std;

int N;
int map[109][109];

ll dp[100][100];

ll dist(int, int);

int main(void) {

	cin >> N;

	memset(map, 0xff, sizeof(int) * 109 * 109);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	cout << dist(0,0) << endl;
}

ll dist(int x, int y) {
	if (x == N-1 && y == N-1) return 1;
	else if (map[y][x] == -1) return 0;
	else if (map[y][x] == 0) return 0;
	else if (dp[y][x] != 0) return dp[y][x];

	int val = map[y][x];
	return dp[y][x] = dist(x, y + val) + dist(x + val, y);
}