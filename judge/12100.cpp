#include <iostream>
#include <algorithm>

#define DEPTH 10

using namespace std;

int N;
int maxNumber = 0;
int depth = 0;


struct Node {
	int board[20][20];
	Node() { memset(board, 0, sizeof(board)); }
	Node(const Node& n) { memcpy(board, n.board, sizeof(board)); }
};

void move(Node curr);

int main(void) {

	cin >> N;

	Node S;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S.board[i][j];
			if (maxNumber < S.board[i][j])
				maxNumber = S.board[i][j];
		}
	}
		
	move(S);

	cout << maxNumber << endl;
	
	return 0;
}

void move(Node curr) {
	
	depth++;

	for (int dir = 0; dir < 4; dir++) {

		Node next(curr);

		int d = (dir < 2) ? 1 : -1;
		int s = (d < 0) ? N - 1 : 0;
		int localMax = 0;
		bool changed = false;

		// Up / Down
		if (dir % 2 == 0) {

			for (int col = 0; col < N; col++) {

				int idx = s;
				int temp = 0;
				for (int row = s, k = 0; k < N; k++, row += d) {

					if (!next.board[row][col]) continue;

					localMax = max(localMax, next.board[row][col]);

					if (temp != next.board[row][col]) {
						next.board[idx][col] = next.board[row][col];
						temp = next.board[row][col];
						if (idx != row) {
							next.board[row][col] = 0;
							changed = true;
						}
						idx += d;
					}
					else {
						next.board[idx - d][col] *= 2;
						next.board[row][col] = 0;
						temp = 0;
						maxNumber = max(maxNumber, next.board[idx-d][col]);
						localMax = max(localMax, next.board[idx-d][col]);
						changed = true;
					}
				}
			}
		}

		// Right / Left
		else {
			for (int row = 0; row < N; row++) {

				int idx = s;
				int temp = 0;
				bool merged = false;
				for (int col = s, k = 0; k < N; k++, col += d) {

					if (!next.board[row][col]) continue;

					localMax = max(localMax, next.board[row][col]);

					if (temp != next.board[row][col]) {
						next.board[row][idx] = next.board[row][col];
						temp = next.board[row][col];
						if (idx != col) {
							next.board[row][col] = 0;
							changed = true;
						}
						idx += d;
					}
					else {
						next.board[row][idx - d] *= 2;
						next.board[row][col] = 0;
						temp = 0;
						maxNumber = max(maxNumber, next.board[row][idx-d]);
						localMax = max(localMax, next.board[row][idx-d]);
						changed = true;
					}
				}
			}
		}

		if (depth < DEPTH && changed && (maxNumber / localMax) < (1 << (DEPTH - depth))) {
			move(next);
			depth--;
		}
	}
}