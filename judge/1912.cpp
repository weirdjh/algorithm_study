#include <iostream>
#include <deque>

using namespace std;

int N;

int sum[100001];

int main(void) {
	cin >> N;

	int lowest = 0;
	int highest = 0;
	int gapMax;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (i == 0) {
			sum[i] = x;
			gapMax = x;
		}
		else {
			sum[i] = sum[i - 1] + x;
			if (lowest > sum[i]) {
				lowest = sum[i];
				highest = lowest;
			}
			else if (highest < sum[i]) highest = sum[i];

			int gap = highest - lowest;
			
			// gap == 0 : descending
			if (gap == 0) gap = x;

			if (gapMax < gap) gapMax = gap;
		}
	}

	cout << gapMax << endl;



	return 0;
}