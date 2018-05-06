#include <iostream>
#define M 10001

using namespace std;

int n, k;

int coin[101];
int dp[10001];

int main(void) {

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}



	for (int i = 1; i <= k; i++) {

		int min = M;
		for (int j = 0; j < n; j++) {
			if (i - coin[j] >= 0) {
				if (min > dp[i - coin[j]] + 1) {
					min = dp[i - coin[j]] + 1;
				}
			}
		}
		dp[i] = min;
	}

	if (dp[k] == M) cout << -1 << endl;
	else cout << dp[k] << endl;

	return 0;
}
