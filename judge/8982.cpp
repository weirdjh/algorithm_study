#include <iostream>
#include <deque>

using namespace std;

typedef struct {
	int left;
	int right;
	int depth;
}horizon;

int N, K;
int waterSum = 0;

deque<horizon> h;
deque<int> topoTree[2501];
deque<pair<int,int>> hose;

bool subtractWater(int d, int s, int e);

int main(void) {

	cin >> N;

	deque<pair<int, int>> p;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		p.push_back({ x,y });
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		hose.push_back({ x1,x2 });
	}

	for (int i = 1; i < p.size(); i++) {
		if (p[i].second == p[i - 1].second) {
			horizon t;
			t.left = p[i-1].first;
			t.right = p[i].first;
			t.depth = p[i].second;
			h.push_back(t);

			waterSum += (t.right - t.left)*t.depth;
		}
	}

	subtractWater(0, 0, p.back().first);
	cout << waterSum << endl;


	return 0;
}

bool subtractWater(int d, int s, int e) {


	if (s == e) return false;

	bool chk = false;


	// find highest list
	deque<int> highest;
	int min = 40000;

	for (int i = 0; i < h.size(); i++) {
		if (s <= h[i].left && h[i].right <= e) {
			if (min > h[i].depth) {
				highest.clear();
				min = h[i].depth;
				highest.push_back(i);
				
			}
			else if (min == h[i].depth) {
				highest.push_back(i);
			}
		}
	}

	// check if highest is hose
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < highest.size(); j++) {
			if (hose[i].first == h[highest[j]].left  && hose[i].second == h[highest[j]].right) {
				chk |= true;
			}
		}
	}

	// check bottom
	chk |= subtractWater(min, s, h[highest[0]].left);
	for (int i = 0; i < highest.size()-1; i++) {
		chk |= subtractWater(min, h[highest[i]].right, h[highest[i + 1]].left);
	}
	chk |= subtractWater(min, h[highest[highest.size() - 1]].right, e);


	if (chk) {
		waterSum -= (min - d)*(e - s);
		cout << waterSum << endl;
	}

	return chk;
}