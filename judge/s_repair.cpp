#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main(void) {

	int T;
	cin >> T;
	for (int q = 1; q <= T; q++) {

		int N, M, K, A, B;
		cin >> N >> M >> K >> A >> B;

		int counter[10];
		int repair[10];
		int customerTime[1001];

		for (int i = 1; i <= N; i++) {
			cin >> counter[i];
		}

		for (int i = 1; i <= M; i++) {
			cin >> repair[i];
		}

		for (int i = 1; i <= K; i++) {
			cin >> customerTime[i];
		}


		int t = 0;
		int idx = 1;
		int done = 0;

		deque<int> waitCounter;
		deque<int> waitRepair;
		deque<int> useA;

		// 창구에 들어가 있는 사람
		int personCounter[10];
		int personRepair[10];

		// 접수창구와 정비창구가 사용가능한지 여부를 저장. 0이면 사용가능.
		int canUseCounter[10];
		int canUseRepair[10];

		int answer = 0;

		memset(canUseCounter, 0, sizeof(canUseCounter));
		memset(canUseRepair, 0, sizeof(canUseRepair));

		while (true) {
			// queue 두개가 모두 비었을 경우.
			if (done == K) break;

			// 도착해서 접수창구 기다리는 사람들.
			for (int j = idx; j <= K; j++) {
				if (customerTime[j] == t) {
					waitCounter.push_back(j);
					idx++;
				}
				if (customerTime[j] > t) break;
			}

			for (int j = 1; j <= N; j++) {
				// 손님이 없었던 경우
				if (canUseCounter[j] == 0) {
					// 접수 기다리던 사람이 있으면.
					if (!waitCounter.empty()) {
						personCounter[j] = waitCounter.front();
						canUseCounter[j] += counter[j];
						waitCounter.pop_front();
						// 손님이 들어간 접수창고가 A이면
						if (j == A) {
							useA.push_back(personCounter[j]);
						}
					}
				}
				// 손님이 있었던 경우
				else {
					canUseCounter[j]--;
					// 있던 손님이 끝나서 나갈 경우
					if (canUseCounter[j] == 0) {
						waitRepair.push_back(personCounter[j]);
						// 접수 기다리던 사람이 있으면,
						if (!waitCounter.empty()) {
							personCounter[j] = waitCounter.front();
							canUseCounter[j] += counter[j];
							waitCounter.pop_front();
							// 손님이 들어간 접수창고가 A이면
							if (j == A) {
								useA.push_back(personCounter[j]);
							}
						}
					}
				}
			}


			// 4 8 10
			for (int j = 1; j <= M; j++) {

				// 손님이 없었던 경우
				if (canUseRepair[j] == 0) {
					// 수리 기다리던 사람이 있으면.
					if (!waitRepair.empty()) {
						personRepair[j] = waitRepair.front();
						canUseRepair[j] += repair[j];
						waitRepair.pop_front();
						// 손님이 들어간 접수창고가 A이면
						if (j == B) {
							for (int l = 0; l<useA.size(); l++) {
								if (useA[l] == personRepair[j]) answer += personRepair[j];
							}
						}
					}
				}
				// 손님이 있었던 경우
				else {
					canUseRepair[j]--;
					// 있던 손님이 끝나서 나갈 경우
					if (canUseRepair[j] == 0) {
						done++;
						// 수리 기다리던 사람이 있으면,
						if (!waitRepair.empty()) {
							personRepair[j] = waitRepair.front();
							canUseRepair[j] += repair[j];
							waitRepair.pop_front();
							// 손님이 들어간 접수창고가 A이면
							if (j == B) {
								for (int l = 0; l<useA.size(); l++) {
									if (useA[l] == personRepair[j]) answer += personRepair[j];
								}
							}
						}
					}
				}
			}
			t++;
		}
		cout << "#" << q << ' ';
		if (answer == 0) cout << -1 << endl;
		else cout << answer << endl;

	}

	return 0;
}