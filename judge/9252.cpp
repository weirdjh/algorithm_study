#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main(void) {

	string A, B;
	cin >> A >> B;

	for(int b = 1; b <= B.size(); b++){
		for (int a = 1; a <= A.size(); a++) {
			if (B[b-1] == A[a-1]) dp[b][a] = max(dp[b][a], dp[b - 1][a - 1]) + 1;
			else dp[b][a] = max(dp[b - 1][a], dp[b][a - 1]);
		}
	}

	int maxSeq = dp[B.size()][A.size()];
	string answer = "";

	int cnt = maxSeq;
	int b = B.size();
	int a = A.size();

	while(cnt){
		if (A[a-1] == B[b-1]) {
			answer = A[a-1] + answer;
			cnt--;
			a--;
			b--;
		}
		else {
			if (dp[b][a] == dp[b - 1][a]) b--;
			else if (dp[b][a] == dp[b][a - 1]) a--;
		}
	}

	
	cout << maxSeq << endl;
	cout << answer << endl;
	return 0;
}