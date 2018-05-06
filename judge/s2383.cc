#include <iostream>
#define MAX(a,b) (a) > (b) ? (a) : (b);
#define MIN(a,b) (a) < (b) ? (a) : (b);

using namespace std;

struct POINT{
	int r,c;
	POINT() {}
	POINT(int r, int c) : r(r), c(c){}
} man[10], stair[2];

int T,M,S;
int match[10];
int map[10][10];

int dist(POINT a, POINT b);
int timeCalculate();

int main(void){

	cin >> T;

	for(int test = 1; test<=T; test++){

		int N;
		cin >> N;
		
		M=0; S=0;
		for(int r=0; r<N; r++){
			for(int c=0; c<N; c++){
				cin >> map[r][c];
				if(map[r][c] > 1){
					stair[S++] = POINT(r,c);
				}
				if(map[r][c] == 1){
					man[M++] = POINT(r,c);
				}
			}
		}

		int answer = 1e9;
		for(int i=0; i<(1<<M); i++){
			for(int j=0; j<M; j++){
				if((i>>j) & 1) match[j] = 1;
				else match[j] = 0;
			}
			int x = timeCalculate();
			answer = MIN(answer, x);
		}

		cout << "#" << test << ' ' << answer << endl;
	}
	
	return 0;
}

int dist(POINT a, POINT b){

	int r = a.r - b.r;
	int c = a.c - b.c;
	r = (r >= 0) ? r : -r;
	c = (c >= 0) ? c : -c;

	return r + c;
}

int timeCalculate(){

	int time;
	int maxTime = 0;

	for(int stairNumber=0; stairNumber<2; stairNumber++){

		int arrive[10] = {0, };
		int desc[3] = {0, };
		int len = map[stair[stairNumber].r][stair[stairNumber].c];

		int manNum = 0;
		for(int i=0; i<M; i++){
			if(match[i] == stairNumber) manNum++;
		}


		int head = 0;
		int tail = 0;

		int finish = 0;

		for(time = 0; time <= 20; time++){

			// arrival
			for(int k=0; k<M; k++){
				if(match[k] == stairNumber){
					if(time == dist(man[k],stair[stairNumber])+1){
						arrive[tail++] = k;
					}
				}
			}

			// stair queue

			for(int k=0; k<3; k++){
				if(desc[k] != 0){
					desc[k]--;
					if(desc[k] == 0){
						finish++;
					}
				}
			}

			for(int k=0; k<3; k++){
				if(desc[k] == 0 && head < tail){
					desc[k] = len;
					head++;
				}
			}

			if(finish == manNum) break;

		}
		maxTime = MAX(maxTime, time);

	}
	return maxTime;

}