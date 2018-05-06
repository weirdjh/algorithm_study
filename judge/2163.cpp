#include <iostream>

using namespace std;

int N, M;

int dp[301][301];

int main(void) {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == 1) dp[i][j] = j-1;
			else if (j == 1) dp[i][j] = i-1;
			else {
				dp[i][j] = dp[i][1] + dp[i][j - 1] + 1;
			}
		}
	}

	cout << dp[N][M] << endl;
	return 0;
}