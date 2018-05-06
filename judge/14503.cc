/*
 Code Implementation Problem : Robot Cleaner
 https://www.acmicpc.net/problem/14503
*/

#include <iostream>

using namespace std;

int N, M;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

int row,col,dir;

int map[50][50];

int cleanTile = 1;

void cleanAI(int r, int c);

int main(void){

	cin >> N >> M;
	cin >> row >> col >> dir;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
	cleanAI(row, col);
	cout << cleanTile - 1 << endl;


	return 0;
}

void cleanAI(int r, int c){

	int mr = r;
	int mc = c;

	while(true){

		int cnt;

		r = mr;
		c = mc;

		if(!map[r][c]) map[r][c] = cleanTile++;

		for(cnt=0; cnt<4; cnt++){
			
			dir = (dir+3)%4;
			mr = r + dirY[dir];
			mc = c + dirX[dir];

			if(mr < 0 || mr >= N || mc < 0 || mc >= M || map[mr][mc]) continue;
			else break;
		}
		if(cnt == 4){
			
			mr = r - dirY[dir];
			mc = c - dirX[dir];
			
			if(mr<0 || mr>=N || mc<0 || mc>=M) return;
		}

		cout << endl;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cout << map[i][j] << '\t';
			}cout << endl;
		}
		
	}
}
