#include <iostream>

using namespace std;

int N, M;
int map[501][501];

int tetro(int i, int j);

int main(void) {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (answer < tetro(i, j)) answer = tetro(i, j);
		}
	}
	
	cout << answer << endl;

	return 0;
}

int tetro(int i, int j) {

	int res = -1;
	int tmp;

	// ㅡ ㅣ
	if (j + 3 <= M) {
		tmp = 0;
		for (int k = 0; k < 4; k++) {
			tmp += map[i][j + k];
		}
		if (res < tmp) res = tmp;
	}
	if (i + 3 <= N) {
		tmp = 0;
		for (int k = 0; k < 4; k++) {
			tmp += map[i + k][j];
		}
		if (res < tmp) res = tmp;
	}
	
	// ㅗ ㄱ ㄴ
	int addNum = 0;
	if (j + 2 <= M) {
		tmp = map[i][j] + map[i][j + 1] + map[i][j + 2];
		if (i - 1 > 0) {
			for (int k = 0; k < 3; k++) {
				if (addNum < map[i - 1][j + k]) addNum = map[i - 1][j + k];
			}
		}
		if (i + 1 <= N) {
			for (int k = 0; k < 3; k++) {
				if (addNum < map[i + 1][j + k]) addNum = map[i + 1][j + k];
			}
		}
		if (addNum != 0) {
			if (res < tmp + addNum) res = tmp + addNum;
		}
	}

	addNum = 0;
	if (i + 2 <= N) {
		tmp = map[i][j] + map[i + 1][j] + map[i + 2][j];
		if (j - 1 > 0) {
			for (int k = 0; k < 3; k++) {
				if (addNum < map[i + k][j - 1]) addNum = map[i + k][j - 1];
			}
		}
		if (j + 1 <= M) {
			for (int k = 0; k < 3; k++) {
				if (addNum < map[i + k][j + 1]) addNum = map[i + k][j + 1];
			}
		}
		if (addNum != 0) {
			if (res < tmp + addNum) res = tmp + addNum;
		}
	}

	// ㅁ Z
	if (j + 1 <= M && i + 1 <= N) {
		tmp = map[i][j] + map[i][j + 1];
		if (res < tmp + map[i + 1][j] + map[i + 1][j + 1]) res = tmp + map[i + 1][j] + map[i + 1][j + 1];
		
		if (j + 2 <= M) {
			if (res < tmp + map[i + 1][j + 1] + map[i + 1][j + 2]) res = tmp + map[i + 1][j + 1] + map[i + 1][j + 2];
		}

		if (j - 1 > 0) {
			if (res < tmp + map[i + 1][j - 1] + map[i + 1][j]) res = tmp + map[i + 1][j - 1] + map[i + 1][j];
		}

		tmp = map[i][j] + map[i + 1][j];
		if (i + 2 <= N) {
			if (res < tmp + map[i + 1][j + 1] + map[i + 2][j + 1]) res = tmp + map[i + 1][j + 1] + map[i + 2][j + 1];
		}
		if (i - 1 > 0) {
			if (res < tmp + map[i - 1][j + 1] + map[i][j + 1]) res = tmp + map[i - 1][j + 1] + map[i][j + 1];
		}
	}

	return res;
}