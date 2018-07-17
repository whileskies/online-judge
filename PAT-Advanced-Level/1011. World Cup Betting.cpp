#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("in", "r", stdin);

	const char status[3] = {'W', 'T', 'L'};
	double odd, ret;
	double profit = 1;

	for (int i = 0; i < 3; i++) {
		double maxOdd = 0;
		int maxStatus = 0;
		for (int j = 0; j < 3; j++) {
			cin >> odd;
			if (odd > maxOdd) {
				maxOdd = odd;
				maxStatus = j;
			}
		}
		cout << status[maxStatus] << " ";
		profit *= maxOdd;
	}

	cout << fixed << setprecision(2) << (profit*0.65-1)*2 << endl;

	return 0;
}