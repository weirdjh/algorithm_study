/*
 Knapsack Exercise
 https://www.acmicpc.net/problem/1535
*/

#include <iostream>
#include <vector>

#define MAX(X,Y) (X>=Y)? X:Y

using namespace std;

int N;
int L[21];
int J[21];

int d[21][100];

int main(void){

	cin >> N;
	for(int i=1 ;i<=N; i++){
		cin >> L[i];
	}

	for(int i=1; i<=N; i++){
		cin >> J[i];
	}

	for(int i=1; i<=N; i++){
		for(int j=0; j<100; j++){
			if(L[i] <= j){
				d[i][j] = MAX(d[i-1][j-L[i]] + J[i], d[i-1][j]);
			}
			else{
				d[i][j] = d[i-1][j];
			}

		}
	}

	cout << d[N][99] << endl;


	return 0;
}
