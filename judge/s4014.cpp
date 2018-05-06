#include<iostream>
#include <vector>

#define ABS(X,Y) (X-Y>0 ? X-Y : Y-X)

using namespace std;

int N, X;
int map[20][20];
int bitchk[20];

bool checkForLine(vector<int> line, int x);

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		int cnt = 0;

		vector<int> tmp;
		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {
				tmp.push_back(map[i][j]);
			}

			if (checkForLine(tmp, X)) {
				cnt++;
			}
			tmp.clear();
		}

		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				tmp.push_back(map[i][j]);
			}
			if (checkForLine(tmp, X)) {
				cnt++;
			}
			tmp.clear();
		}

		cout << "#" << test_case << ' ' << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

bool checkForLine(vector<int> line, int x) {

	int len = line.size();

	// bit 초기화
	for (int i = 0; i < len; i++) {
		bitchk[i] = 0;
	}

	// 왼쪽 -> 오른쪽
	for (int i = 0; i < len - 1; i++) {
		// 차이가 2이상
		if (ABS(line[i], line[i + 1]) >= 2) {
			return false;
		}

		// 차이가 1
		else if (ABS(line[i], line[i + 1]) == 1) {

			// 큰거 -> 작은거 or 작은거-> 큰거
			int idx, co;
			if (line[i] - line[i + 1] == 1) {
				idx = i + 1;
				co = 1;
			}
			else {
				idx = i;
				co = -1;
			}

			// 밖으로 삐죽
			if (idx + co*(x - 1) >= len || idx + co*(x - 1) < 0) {
				return false;
			}

			// 제약조건
			for (int j = 0; j < x; j++) {
				if (line[idx + j*co] != line[idx] || bitchk[idx + j*co]) {
					return false;
				}
			}

			for (int j = 0; j < x; j++) {
				bitchk[idx + j*co] = 1;
			}
		}
	}

	return true;

}