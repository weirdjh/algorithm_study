#include <iostream>

#define MIN(a,b) (a) < (b) ? (a) : (b)

using namespace std;

int T;
int D, W, K;
int film[13][20];
int med[20];

int answer;

void dfs(int n);

int main(void) {
	cin >> T;

	for (int test = 1; test <= T; test++) {


		cin >> D >> W >> K;

		for (int row = 0; row < D; row++) {
			for (int col = 0; col < W; col++) {
				cin >> film[row][col];
			}
		}

		answer = 1e9;
		dfs(0);
		cout << "#" << test << ' ' <<  answer << endl;
	
	}

	return 0;
}

void dfs(int n) {

	
	if (n == D) {

		for (int c = 0; c < W; c++) {

			int cnt = 1;
			int cmp = (med[0] < 0) ? film[0][c] : med[0];
			bool local_chk = false;

			for (int r = 1; r < D; r++) {

				int tmp = (med[r] < 0) ? film[r][c] : med[r];
				
				if (cmp == tmp) cnt++;
				else {
					cmp = tmp;
					cnt = 1;
				}

				if (cnt == K) {
					local_chk = true;
					break;
				}

			}
			if (!local_chk) return;
		}

		int ret = 0;
		for (int i = 0; i < D; i++) {
			//cout << med[i] << ' ';
			if (med[i] >= 0) ret++;
		}//cout << endl;
		answer = MIN(answer, ret);
		
		return;
	}

	// 안바꾸던가
	med[n] = -1;
	dfs(n + 1);

	// A로 바꾸고 넘기던가
	med[n] = 0;
	dfs(n + 1);
	med[n] = -1;

	// B로 바꾸고 넘기던가
	med[n] = 1;
	dfs(n + 1);
	med[n] = -1;
}