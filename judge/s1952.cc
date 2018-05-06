#include <iostream>

#define MIN(a,b) (a) < (b) ? (a) : (b)

using namespace std;

int T;
int D,M,TM,Y;
int plan[15];
int month[15];

int threeMonth(int n);

int main(void){

	cin >> T;
	for(int test = 1; test <= T; test++){
		cin >> D >> M >> TM >> Y;
		for(int p = 0; p < 12; p++){
			cin >> plan[p];
		}

		// 1D vs 1M
		for(int p = 0; p < 12; p++){
			month[p] = (plan[p] * D > M) ? M : plan[p] * D;
		}

		int answer = 1e9;
		for(int p = 0; p < 12; p++){
			int x = threeMonth(p);
			answer = MIN(answer , x);
		}
		answer = MIN(answer , Y);
		cout << "#" << test << ' ' << answer << endl;
	}

	return 0;
}

int threeMonth(int n){

	if(n >= 12) return 0;

	int x = 1e9;
	int y = 1e9;
	int s = month[n] + month[n+1] + month[n+2];

	if(s > TM){
		x = TM + threeMonth(n+3);
	}
	else{
		y = month[n] + threeMonth(n+1);
	}

	return MIN(x,y);
}