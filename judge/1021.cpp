#include <iostream>
#include <vector>

using namespace std;

vector<int> Queue;
int *pickNumber;

int N, M;

void QueueInit();
void QueueRotate(int n);

int main(void) {

	cin >> N >> M;

	pickNumber = new int(M);

	for (int i = 0; i < M; i++) {
		cin >> pickNumber[i];
	}

	QueueInit();

	int ret = 0;
	int move = 0;
	for (int i = 0; i < M; i++) {

		if (pickNumber[i] - 1 <= N - pickNumber[i] + 1) {
			move = pickNumber[i] - 1;

		}
		else {
			move = N - pickNumber[i] + 1;
		}
		QueueRotate(pickNumber[i] - 1);
		ret += move;

		if (i + 1 < M) {
			for (int k = 0; k < Queue.size(); k++) {
				if (pickNumber[i + 1] == Queue[k]) {
					pickNumber[i + 1] = k + 1;
					break;
				}
			}
		}
		N = N - 1;
		cout << move << ' ';
	}

	cout << ret << endl;

	return 0;
}

void QueueInit()
{
	for (int i = 1; i <= N; i++) {
		Queue.push_back(i);
	}

}

void QueueRotate(int n)
{
	for (int i = 0; i < n; i++) {
		Queue.push_back(Queue[i]);
	}
	for (int i = 0; i < n; i++) {
		Queue.erase(Queue.begin());
	}
	Queue.erase(Queue.begin());
}