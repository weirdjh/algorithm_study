/*
 Make correct equation
 https://www.acmicpc.net/problem/5557
 */

#include <iostream>

using namespace std;

int N;
int num[101];
long long d[101][1001];
int result;

long long numberOfEquation(int idx, int sum);

int main(void){
	cin >> N;
	for(int i=0; i<N-1; i++){
		cin >> num[i];
	}
	cin >> result;

	for(int i=0; i<101; i++){
		for(int j=0; j<1001; j++){
			d[i][j] = -1;
		}
	}

	cout << numberOfEquation(0,num[0]) << endl;

	return 0;
}

long long numberOfEquation(int idx, int sum){

	if (sum < 0 || sum > 20){
		return 0;
	}

	if (idx == N-2){
		if(sum == result){
			return d[idx][sum] = 1;
		}
		else{
			return d[idx][sum] = 0;
		}
	}

	if(d[idx][sum] != -1){
		return d[idx][sum];
	}

	long long val = 0;
	val += numberOfEquation(idx+1, sum + num[idx+1]);
	val += numberOfEquation(idx+1, sum - num[idx+1]);

	return d[idx][sum] = val;
}
