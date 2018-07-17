#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
	if (n <= 1)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int toDec(string n, int radix)
{
	int dec = 0;
	for (int i = 0; i < n.size(); i++)
		dec = dec * radix + (n[i] - '0');
	return dec;
}

string reverseWithRadix(int n, int radix)
{
	string ret;
	while (n) {
		ret += n % radix + '0';
		n /= radix;
	}
	return ret;
}

int main()
{
	//freopen("in", "r", stdin);

	int N, D;

	while (cin >> N >> D) {
		if (N < 0)
			break;
		if (isPrime(N) && isPrime(toDec(reverseWithRadix(N, D), D)))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}


	return 0;
}