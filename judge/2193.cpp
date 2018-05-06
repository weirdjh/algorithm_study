#include <iostream>
#include <string>

#define ll long long

using namespace std;

int N;


int main(void) {

	cin >> N;

	ll zero = 1;
	ll one = 0;

	for (int i = 1; i < N; i++) {
		ll tmp = one;
		one = zero + one;
		zero = tmp;
	}
	cout << zero + one << endl;

	return 0;
}
