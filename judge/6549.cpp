#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define max(x,y) (x) > (y)? (x) : (y);
#define ll long long


using namespace std;

int stk[100001];
ll arr[100002] = { -1, };

int main(void) {

	int N;
	
	while (scanf("%d", &N) && N) {

		int top = 1;
		ll maxSquare = 0;

		stk[0] = 0;
		arr[N + 1] = 0;
		for (int i = 1; i <= N + 1; i++) {
			if (i <= N) cin >> arr[i];
			if (arr[stk[top]] < arr[i]) stk[++top] = i;
			else {
				while (arr[stk[top]] > arr[i]) {
					maxSquare = max(maxSquare, arr[stk[top]] * (i - stk[top-1] -1));
					top--;
				}
				stk[++top] = i;
			}
		}
		cout << maxSquare << endl;
	}

	return 0;
}