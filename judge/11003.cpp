#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, L;
vector<int> list;

bool cmp(int a, int b) {
	if (list[a] < list[b]) return true;
	else return false;
}

int main(void) {

	cin >> N >> L;
	
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		list.push_back(x);
	}

	int cur = 0;	// number to be printed
	deque<int> wait;

	for (int i = 0; i < N; i++) {
		
		if (i - cur + 1 > L) {
			if (!wait.empty()) {
				if (list[wait.front()] < list[i]) {
					while (i - wait.front() + 1 > L) {
						wait.pop_front();
					}
					cur = wait.front();
					wait.pop_front();
					wait.push_back(i);
					sort(wait.begin(), wait.end(), cmp);
				}
				else {
					cur = i;
					wait.clear();
				}
			}
			else cur = i;
		}
		else if (list[i] <= list[cur]) {
			cur = i;
			wait.clear();
		}
		else {
			if (!wait.empty() && list[wait.front()] >= list[i]) {
				wait.clear();
				wait.push_back(i);
			}
			else {
				wait.push_back(i);
				sort(wait.begin(), wait.end(), cmp);
			}
		}
		
		cout << list[cur] << ' ';
	}cout << endl;

	return 0;
}