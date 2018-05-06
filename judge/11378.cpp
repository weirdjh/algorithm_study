#include <iostream>
#include <deque>

using namespace std;

int N, M, K;

// nth work -> mth worker?
deque<int> work[1001];
bool worker[1001];
bool workDone[1001];

int main(void) {

	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		while (x--) {
			int y;
			cin >> y;
			work[y].push_back(i);
		}
	}
	
	int workerNum = 0;
	int size = 1;

	int answer = 0;

	while (size <= M) {
		//cout << "size : " << size << endl;
		for(int i = 1; i <= M; i++) {

			for (int k = 0; k < work[i].size(); k++) {

				// worker : ok && workDone : false
				if (work[i].size() == size && workDone[i] == 0) {
					if (worker[work[i][k]] == 0) worker[work[i][k]] = 1;
					else if (K > 0) K--;
					else continue;
					
					//cout << '#' << i << ' ' << work[i][k] << endl;
					workDone[i] = 1;
					answer++;
				}
			}
		}
		size++;
	}

	cout << answer << endl;

	return 0;
}