#include <iostream>
#include <deque>
#include <string>
#include <cstring>

using namespace std;

string par;

int sum(int s, int e);

int main(void) {
	cin >> par;

	deque<char> stk;
	bool cor = true;
	for (int i = 0; i < par.size(); i++) {
		// start with ( [
		if (stk.empty() && (par[i] == ')' || par[i] == ']')) {
			cor = false;
			break;
		}
		// open par
		else if (par[i] == '(') stk.push_back('(');
		else if (par[i] == '[') stk.push_back('[');

		// close par
		else if (par[i] == ')') {
			if (stk.back() == '(') {
					stk.pop_back();
			}
			else {
				cor = false;
				break;
			}
		}
	
		else if (par[i] == ']') {
			if (stk.back() == '[') {
				stk.pop_back();
			}
			else {
				cor = false;
				break;
			}
		}
	}
	if (!stk.empty()) cor = false;

	int answer;
	if (!cor) answer = 0;
	else answer = sum(0, par.size() - 1);

	cout << answer << endl;

	return 0;
}

int sum(int s, int e) {

	if (s - e == 1) return 1;

	int start = s;
	int end;
	int idx = s;

	int rst = 0;

	int mul;
	while(idx <= e){

		if (par[idx] == '(') {

			start = idx + 1;

			int x = 1;
			while (x) {
				idx++;
				if (par[idx] == '(') x++;
				else if (par[idx] == ')') x--;
			}

			end = idx - 1;
			rst += (2 * sum(start, end));
		}
		else if (par[idx] == '[') {

			start = idx + 1;

			int x = 1;
			while (x) {
				idx++;
				if (par[idx] == '[') x++;
				else if (par[idx] == ']') x--;
			}

			end = idx - 1;
			rst += (3 * sum(start, end));

		}
		idx++;
	}
	return rst;

}