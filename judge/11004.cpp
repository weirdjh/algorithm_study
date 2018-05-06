#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int N, K;

long long arr[5000001];  //이거랑
int main() {

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	sort(arr, arr + n);
	cout << arr[k - 1];
	return 0;
}