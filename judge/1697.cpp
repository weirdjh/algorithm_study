#include <iostream>
#include <deque>

using namespace std;

int N, K;
int visit[200000];

int main(void) {

	cin >> N >> K;

	deque<int> que;
	que.push_back(N);

	bool find = false;
	int cnt = 0;

	while (!find) {
		int size = que.size();
		cnt++;
		
		while (size--) {
			int x = que.front();
			que.pop_front();
			visit[x] = 1;
			
			if (x == K) {
				find = true;
			}

			if (x - 1 >= 0 && !visit[x - 1]) que.push_back(x - 1);
			if (x + 1 <= K && !visit[x + 1]) que.push_back(x + 1);
			if (x < K && !visit[x * 2]) que.push_back(x * 2);
		}
	}

	cout << cnt-1 << endl;
	return 0;
}
