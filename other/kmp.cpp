/*
# Input:
ABCDABCDABEEABCDABE
ABCDABE
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){

	string S;
	string W;

	getline(cin, S);
	getline(cin, W);

	int M = S.size();
	int N = W.size();

	// Make Failure Table
	vector<int> T(N, 0);
	for(int i=1, j=0; i<N; i++){
		while(j>0 && W[i] != W[j]){
			j = T[j-1];
		}
		if(W[i] == W[j]){
			T[i] = ++j;
		}
	}
	
	// KMP
	vector<int> ans;
	for(int i=0, j=0; i<M; i++){
		while(j>0 && S[i] != W[j]){
			j = T[j-1];
		}
		if(S[i] == W[j]){
			if(j == N-1){
				ans.push_back(i-j+1);
				j = T[j];
			}
			else{
				j++;
			}
		}
	}

	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << ' ';
	}cout << endl;

	return 0;
}
