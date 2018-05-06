#include <iostream>

using namespace std;

int T;

int main(void) {

	cin >> T;
	while (T--) {

		// input
		int N, M;
		cin >> N >> M;

		int matrix[35][35];
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				int x;
				cin >> x;
				matrix[i][j] = x;
				matrix[j][i] = x;
			}	
		}

		for (int i = 0; i < N; i++) {
			matrix[i][i] = 0;
		}

		char place[35];
		int play[35];
		int satisfied[35];

		int airportIndex;
		int hotelIndex[35];
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			char p;
			cin >> p;
			place[i] = p;

			if (p == 'P') {
				cin >> play[i] >> satisfied[i];
			}
			else if (p == 'A') {
				airportIndex = i;
			}
			else if (p == 'H') {
				hotelIndex[cnt++];
			}

		}

		// make plan

		// M일 동안.

		int que[35];
		int queIndex = 0;

		for (int i = 0; i < M; i++) {

		}
	}


	return 0;
}