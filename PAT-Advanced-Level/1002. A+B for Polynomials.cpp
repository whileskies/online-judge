#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

double a[1010], b[1010], ret[1010];
const int maxExp = 1003;

void readPloy()
{
	int N, exp;
	double coe;

	cin >> N;
	while (N--) {
		cin >> exp >> coe;
		a[exp] += coe;
	}

	cin >> N;
	while (N--) {
		cin >> exp >> coe;
		b[exp] += coe;
	}
}

int main()
{	
	//freopen("in", "r", stdin);
	readPloy();

	int sumTerms = 0;
	for (int i = 0; i <= maxExp; i++) {
		ret[i] += (a[i] + b[i]);
		if (ret[i])
			sumTerms++;
	}

	cout << sumTerms;
	for (int i = maxExp; i >= 0; i--) {
		if (ret[i] == 0) continue;
		cout << " " << i << " " << fixed << setprecision(1) << ret[i];
	}


	return 0;
}