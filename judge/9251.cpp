#include <iostream>
#include <string>

#define MAX(A,B) (A)>=(B)? (A):(B)

using namespace std;

int dp[1000][1000];

int main(void) {

	string A, B;

	cin >> A >> B;

	int max = 0;
	for (int b = 1; b <= B.size(); b++) {
		
		for (int a = 1; a <= A.size(); a++) {
			if (A[a - 1] == B[b - 1]) dp[b][a] = dp[b - 1][a - 1] + 1;
			else dp[b][a] = MAX(dp[b - 1][a], dp[b][a - 1]);
			
			if (max < dp[b][a]) max = dp[b][a];
		}
	}

	cout << max << endl;

	return 0;
}