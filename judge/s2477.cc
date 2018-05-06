#include <iostream>

using namespace std;

struct MAN{
	int time;
	int man;
	MAN() {}
	MAN(int time, int man) : time(time), man(man) {}
}INFO[9], REP[9];

int T;
int N, M, K;
int A, B;
int a[10];
int b[10];
int t[1001];

int useA[1001];
int useAB[1001];
int waitI[1001];
int waitR[1001];

int main(void){

    cin >> T;
	for(int test=1; test<=T; test++){
		cin >> N >> M >> K >> A >> B;

		for(int info = 1; info <= N; info++){
			cin >> a[info];
		}

		for(int rep = 1; rep <= M; rep++){
			cin >> b[rep];
		}

		for(int man = 1; man <= K; man++){
			cin >> t[man];
		}

		int time = 0;

		int headI = 0;
		int tailI = 0;

		int headR = 0;
		int tailR = 0;

		int useIdx = 0;
		int useAB_idx = 0;

		int finish = 0;

		while(true){

			for(int man = 1; man <=K; man++){
				if(t[man] == time) waitI[tailI++] = man;
			}


			// into information
			for(int info = 1; info <= N; info++){
				if(INFO[info].time != 0) {
					INFO[info].time--;
					if(INFO[info].time == 0){
						waitR[tailR++] = INFO[info].man;

						// man who use A
						if(info == A){
							useA[useIdx++] = INFO[info].man;
						}
					}
				}
			}

			for(int info = 1; info <= N; info++){
				if(INFO[info].time == 0 && headI < tailI){
					INFO[info] = MAN(a[info], waitI[headI]);
					headI++;
				}
			}

			// into repair center
			for(int rep = 1; rep <= M; rep++){
				if(REP[rep].time != 0){
					REP[rep].time--;
					if(REP[rep].time == 0){
						finish++;

						// man who use B
						if(rep == B){
							for(int i=0; i<useIdx; i++){
								if(useA[i] == REP[rep].man){
									useAB[useAB_idx++] = REP[rep].man;
								}
							}
						}

					}
				}
			}

			for(int rep = 1; rep <=M; rep++){
				if(REP[rep].time == 0 && headR < tailR){
					REP[rep] = MAN(b[rep], waitR[headR]);
					headR++;
				}
			}

			if(finish == K) break;

			cout << "#" << time << endl;
			cout << "REP ";
			for(int i=1; i<=M; i++){
				cout << REP[i].time << ' ';
			}cout << endl;

			time++;
		}

		int answer = 0;
		for(int i=0; i<useAB_idx; i++){
			answer += useAB[i];
		}
        if(answer == 0) answer = -1;
		cout << "#" << test << ' ' << answer << endl;
	}

	return 0;
}
