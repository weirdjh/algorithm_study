#include <iostream>

using namespace std;

int M, N;
bool arr[1000001];

int main(void) {

	cin >> M >> N;

	for (int i = 2; i * i <= N; i++) {
		
		for (int j = i*i; j <= N; j+=i) {
			arr[j] = 1;
		}
	}
	for (int i = M; i <= N; i++) {
		if (!arr[i]) {
			cout << i << endl;
		}
	}

	return 0;
}