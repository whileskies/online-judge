#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int maxe = 1010;
double a[maxe], b[maxe];
double ret[2*maxe];
int digit;

void ReadPoly()
{
	int k, e;
	double c;

	cin >> k;
	while (k--) {
		cin >> e >> c;
		a[e] += c;
	}

	cin >> k;
	while (k--) {
		cin >> e >> c;
		b[e] += c;
	}
}

void Product()
{
	for (int i = 0; i < maxe; i++) {
		if (a[i] != 0) {
			for (int j = 0; j < maxe; j++) {
				if (b[j] != 0) {
					ret[i+j] += a[i]*b[j];
				}
			}
		}
	}
}

int main()
{
	//freopen("in", "r", stdin);

	ReadPoly();
	Product();

	int k = 0;

	for (int i = 0; i < 2*maxe; i++)
		if (ret[i])
			k++;

	cout << k;

	for (int i = 2*maxe-1; i >= 0; i--) {
		if (ret[i])
			cout << fixed << setprecision(1) 
				 << " " << i << " " << ret[i];
	}

	return 0;
}