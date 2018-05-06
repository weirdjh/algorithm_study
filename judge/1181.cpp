#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string str[20000];

bool cmp(const string&, const string &);

int main(void) {

	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> str[i];
	}
	sort(str, str + N, cmp);

	for (int i = 0; i < N; i++) {
		if (str[i] == str[i + 1]) continue;
		else cout << str[i] << endl;
	}

	return 0;
}

bool cmp(const string& a, const string & b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}