#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int T;

bool isGrouped(pair<pair<int, int>, int>, pair<pair<int, int>, int>);

int main(void) {

	cin >> T;

	vector<int> answer;
	while (T--) {
		int N;

		cin >> N;

		vector<pair<pair<int,int>,int>> v;
		vector<int> chk;
		chk.resize(N,0);

		// input
		for(int i=0; i<N; i++){
			int x, y, R;
			cin >> x >> y >> R;
			v.push_back({ {x,y},R });
		}

		// bfs
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			deque<pair<pair<int, int>, int>> que;
			if (!chk[i]) {
				que.push_back({ { v[i].first.first, v[i].first.second },v[i].second });
				chk[i] = 1;
				cnt++;
			}
			while (!que.empty()) {
				pair<pair<int, int>, int> groupBase = que[0];
				que.pop_front();

				for (int j = 0; j < N; j++) {
					pair<pair<int, int>, int> point = { {v[j].first.first,v[j].first.second},v[j].second };
					if (!chk[j] && isGrouped(groupBase, point)) {
						que.push_back(point);
						chk[j] = 1;
					}
				}
				
			}
		
		}
		answer.push_back(cnt);

	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}

bool isGrouped(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	int x = (a.first.first - b.first.first) * (a.first.first - b.first.first);
	int y = (a.first.second - b.first.second) * (a.first.second - b.first.second);
	int z = (a.second + b.second) * (a.second + b.second);
	if (x+y <= z) return true;
	return false;
}