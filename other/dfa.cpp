/*
 # Input:
 ABCDABCDABEEABCDABE
 ABCDABE
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(void){

	string S;
	string W;

	getline(cin, S);
	getline(cin, W);

	int M = S.size();
	int N = W.size();
	int R = alphabet.size();

	/* Construct DFA */

	int** DFA = new int* [N];
	for(int i=0; i<N; i++){
		DFA[i] = new int [R]();
	}

	DFA[0][alphabet.find(W[0])] = 1;

	// i : state, j : LPS(Longest Prefix Suffix)
	for(int i=1, j=0; i<N; i++){

		// next state of i'th state can be that of j'th
		for(int c=0; c<R; c++){
			DFA[i][c] = DFA[j][c];
		}

		// (i) state -> W[i] -> (i+1) state
		DFA[i][alphabet.find(W[i])] = i+1;

		// update LPS
		j = DFA[j][alphabet.find(W[i])];
	}
	
	/* Search With DFA */

	vector<int> ans;
	for(int i=0, j=0; i<M; i++){
		j = DFA[j][alphabet.find(S[i])];

		if(j == N){
			ans.push_back(i-N+1);
			j = 0;
		}
	}

	cout << "total : " <<  ans.size() << endl;
	cout << "index : ";
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << ' ';
	}cout << endl;

	return 0;
}
