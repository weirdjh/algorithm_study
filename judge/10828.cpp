#include <iostream>
#include <deque>
#include <string>

using namespace std;

int N;

int main(void) {

	cin >> N;

	deque<int> arr;
	deque<int> answer;

	while (N--) {
		string command;
		cin >> command;

		if (command == "push") {
			int x;
			cin >> x;
			arr.push_back(x);

		}
		else if (command == "pop") {
			if (arr.empty()) answer.push_back(-1);
			else {
				answer.push_back(arr.back());
				arr.pop_back();
			}
		}
		else if (command == "size") {
			answer.push_back(arr.size());
		}
		else if (command == "empty") {
			if (arr.empty()) answer.push_back(1);
			else answer.push_back(0);
		}
		else if (command == "top") {
			if (arr.empty()) answer.push_back(-1);
			else answer.push_back(arr.back());
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}