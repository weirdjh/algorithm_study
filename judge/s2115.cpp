#include <iostream>
#include <cstring>

#define MAX(a,b) (a)>(b) ? (a):(b)

using namespace std;

int T;
int hive[10][10];

int main(void) {

	cin >> T;
	for (int test = 1; test <= T; test++) {
		int N, M, C;
		cin >> N >> M >> C;

		memset(hive, 0, sizeof(hive));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> hive[i][j];
			}
		}

		int makeHoney[10][10];
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N - M + 1; col++) {
				
				int bestHoney = 0;
				for (int i = 0; i < (1 << M); i++) {

					int sum = 0;
					int square = 0;
					for (int j = 0; j < M; j++) {
						if ((i >> j) & 1) {
							sum += hive[row][col + j];
							square += (hive[row][col + j] * hive[row][col + j]);
						}
					}
					if (sum <= C) {
						if (bestHoney < square) bestHoney = square;
					}
				}
				makeHoney[row][col] = bestHoney;
			}
		}
		
		int answer = 0;
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N - M + 1; col++) {

				for (int r = row; r < N; r++) {
					for (int c = 0; c < N - M + 1; c++) {
						if (row == r && c - col >= M) {
							answer = MAX(answer, makeHoney[row][col] + makeHoney[r][c]);
						}
						else if (row != r) {
							answer = MAX(answer, makeHoney[row][col] +makeHoney[r][c]);
						}
					}
				}

			}
		}

		cout << "#" << test << ' ' << answer << endl;

	}

	return 0;
}
