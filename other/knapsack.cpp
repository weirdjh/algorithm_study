/*
#Input:
20 5
6 2
8 5
5 6
9 6
3 4
*/

#include <iostream>
#include <vector>

#define MAX(X,Y) (X>=Y)? X:Y

using namespace std;

int W, N;

typedef struct item{
	int w;
	int v;
	item(): w(), v() {}
	item(int w, int v): w(w), v(v) {}
}ITEM;

vector<ITEM> item;

int knapsack(int W, int idx);

int main(void){

	cin >> W >> N;
	for (int i = 0; i < N; i++){
		int w, v;
		cin >> w >> v;
		item.push_back(ITEM(w,v));
	}
	
	cout << knapsack(W, 0) << endl;


	return 0;
}

int knapsack(int W, int idx){
	int* d = new int[W+1]();
	int* t = new int[W+1];

	for(int i=0; i<N; i++){
		for(int j=1; j<=W; j++){
			t[j] = d[j];
			if(item[i].w <= j){
				d[j] = MAX(t[j - item[i].w] + item[i].v, t[j]);
			}
		}
		for(int j=0; j<=W; j++){
			cout << d[j] << '\t';
		}cout << endl;
	}

	return d[W];
}
