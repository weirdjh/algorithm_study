#include <iostream>
#define ll long long

using namespace std;

int N, M;

int main(void) {

	cin >> N >> M;

	ll sum = 0;
	ll num[1000] = { 0, };

	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		sum += x;
		num[sum % M]++;
	}

	long long answer = num[0];
	for (int i = 0; i < M; i++) {
		answer += (num[i] * (num[i]-1)) / 2;
	}
	cout << answer << endl;

	return 0;
}