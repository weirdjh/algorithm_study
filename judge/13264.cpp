#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

deque<pair<int,string>> list;

bool compare(pair<int, string> a, pair<int, string> b);

int main(void) {

	string s;

	cin >> s;

	int idx = 0;
	while (!s.empty()) {
		list.push_back({ idx++,s });
		s.erase(s.begin());
	}

	sort(list.begin(), list.end(), compare);
	
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].first << endl;
	}

	return 0;
}
bool compare(pair<int, string> a, pair<int, string> b) {
	return a.second < b.second;
}