#include <iostream>

#define ll long long
#define MOD 1000000000

using namespace std;

int N, K;
ll dp[201][201];

int main(void) {

	cin >> N >> K;

	for (int k = 0; k <= K; k++) {
		dp[0][k] = 1;
	}

	for (int n = 1; n <= N; n++) {
		for (int k = 1; k <= K; k++) {
			dp[n][k] = dp[n - 1][k] + dp[n][k - 1];
			dp[n][k] %= MOD;
		}
	}

	cout << dp[N][K] << endl;

	return 0;
}