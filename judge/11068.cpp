#include <iostream>
#include <deque>

using namespace std;

int T;

bool hoimoon(int n, int M);
string reverseString(string s);

int main(void) {

	deque<int> answer;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		bool chk = false;
		for (int i = 2; i <= 64; i++) {
			if (hoimoon(n, i)) {
				chk = true;
				break;
			}
		}
		if (chk) answer.push_back(1);
		else answer.push_back(0);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}

bool hoimoon(int n, int M) {
	deque<int> s;
	while (n) {
		s.push_back(n % M);
		n /= M;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}
