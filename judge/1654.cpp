#include <iostream>
#define ll long long

using namespace std;

ll K, N;
ll lan[10000];

ll low = 0;
ll high = 0;

int main(void) {

	cin >> K >> N;
	ll sum = 0;

	for (int i = 0; i < K; i++) {
		cin >> lan[i];
		sum += lan[i];
		if (high < lan[i]) high = lan[i];
	}

	ll mid = sum / N;
	ll answerMax = 0;
	ll cnt;

	do {

		//cout << low << ' ' << mid << ' ' << high << endl;
		cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += (lan[i] / mid);
		}
		//cout << "# " << cnt << endl;
		if (cnt < N) {
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else{
			if (answerMax < mid) answerMax = mid;
			low = mid + 1;
			mid = (low + high) / 2;
		}

	} while (low <= high);

	cout << answerMax << endl;

	return 0;
}