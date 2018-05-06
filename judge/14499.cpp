#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int Dx, Dy;
int K;

int map[22][22];
int dice[6] = { 0, 0, 0, 0, 0, 0 };

// dice
int diceTop = 0;
int diceBottom = 5;
int diceLeft = 3;
int diceRight = 2;
int diceFront = 4;
int diceBack = 1;

int main(void) {

	cin >> N >> M >> Dy >> Dx >> K;

	memset(map, -1, sizeof(int) * 22 * 22);

	Dx++;
	Dy++;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	vector<int> answer;

	for (int i = 0; i < K; i++) {
		int command;
		cin >> command;

		switch (command) {
		
			int x;
			// East
			case 1:
				if (map[Dy][Dx + 1] == -1) break;
				else {
					x = diceTop;
					diceTop = diceLeft;
					diceLeft = diceBottom;
					diceBottom = diceRight;
					diceRight = x;

					Dx++;
					if (map[Dy][Dx] != 0) {
						dice[diceBottom] = map[Dy][Dx];
						map[Dy][Dx] = 0;
					}
					else {
						map[Dy][Dx] = dice[diceBottom];
					}
					answer.push_back(dice[diceTop]);
				}
				break;

			// West
			case 2:
				if (map[Dy][Dx - 1] == -1) break;
				else {
					x = diceTop;
					diceTop = diceRight;
					diceRight = diceBottom;
					diceBottom = diceLeft;
					diceLeft = x;
					Dx--;
					if (map[Dy][Dx] != 0) {
						dice[diceBottom] = map[Dy][Dx];
						map[Dy][Dx] = 0;
					}
					else {
						map[Dy][Dx] = dice[diceBottom];
					}
					answer.push_back(dice[diceTop]);
				}
				break;

			// North
			case 3:
				if (map[Dy - 1][Dx] == -1) break;
				else {
					x = diceTop;
					diceTop = diceFront;
					diceFront = diceBottom;
					diceBottom = diceBack;
					diceBack = x;
					Dy--;
					if (map[Dy][Dx] != 0) {
						dice[diceBottom] = map[Dy][Dx];
						map[Dy][Dx] = 0;
					}
					else {
						map[Dy][Dx] = dice[diceBottom];
					}
					answer.push_back(dice[diceTop]);
				}
				break;

			// South
			case 4:
				if (map[Dy + 1][Dx] == -1) break;
				else {
					x = diceTop;
					diceTop = diceBack;
					diceBack = diceBottom;
					diceBottom = diceFront;
					diceFront = x;
					Dy++;
					if (map[Dy][Dx] != 0) {
						dice[diceBottom] = map[Dy][Dx];
						map[Dy][Dx] = 0;
					}
					else {
						map[Dy][Dx] = dice[diceBottom];
					}
					answer.push_back(dice[diceTop]);
				}
				break;

			}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}