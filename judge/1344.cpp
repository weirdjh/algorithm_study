#include <iostream>
#include <math.h>

using namespace std;

double A, B;

int num[12] = {0,1,4,6,8,9,10,12,14,15,16,18};

int C[19][19];
double posNotPrime(int n, double p);


int main(void) {

	cin >> A >> B;


	//mCn
	for (int m = 1; m <= 18; m++) {
		for (int n = 0; n <= m; n++) {
			if (m == 1) C[m][n] = m;
			else C[m][n] = C[m - 1][n] + C[m - 1][n - 1];
		}
	}

	double a=.0,b=.0;
	for (int i = 0; i < 12; i++) {
		a += posNotPrime(num[i], double( A / 100 ));
		b += posNotPrime(num[i], double( B / 100 ));
	}
	
	cout.precision(16);

	cout << 1 - a*b << endl;

	return 0;
}

double posNotPrime(int n, double p) {
	if (p == 0 && n == 18) return 0;
	return C[18][n] * pow(p, n) * pow(1 - p, 18 - n);
}