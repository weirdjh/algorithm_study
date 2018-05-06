#include <iostream>
#include <string>

using namespace std;

string stringPlus(string x, string y);

int main(void) {

	string A, B, C, D;
	cin >> A >> B >> C >> D;

	string x = A + B;
	string y = C + D;

	cout << stringPlus(x, y) << endl;

	return 0;
}

string stringPlus(string x, string y) {

	string result = "";

	if (x.size() < y.size()) {
		string tmp = x;
		x = y;
		y = tmp;
	}

	x = "0" + x;
	while (x.size() != y.size()) {
		y = "0" + y;
	}

	int buf = 0;
	for (int i = x.size() - 1; i >= 0; i--) {
		int nx = x[i] - '0';
		int ny = y[i] - '0';
		int sum = nx + ny;

		if (buf == 1) {
			sum += 1;
			buf = 0;
		}

		char t = '0' + (sum % 10);
		result = t + result;

		if (sum >= 10) {
			buf = 1;
		}

	}

	if (result[0] == '0') {
		result.erase(result.begin());
	}

	return result;
}