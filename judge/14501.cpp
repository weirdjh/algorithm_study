#include <iostream>

#define MAX(a,b) (a) > (b) ? (a) : (b)

using namespace std;

int N;
int T[15];
int P[15];
int save[15];

int profit(int n);

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	cout << profit(0) << endl;
	
	return 0;
}

int profit(int n) {
	if (n == N) return 0;
	else if (n > N) return -0xffffff;
	else if (save[n] != 0) return save[n];
	
	return save[n] = MAX(profit(n + 1), P[n] + profit(n + T[n]));
}