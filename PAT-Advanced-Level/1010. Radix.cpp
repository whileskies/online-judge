#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define LL long long

const LL MAX = 1LL<<63-1;

int Char2Int(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	if (ch >= 'a' && ch <= 'z')
		return ch - 'a' + 10;
}

LL ToDec(const string& num, LL radix)
{
	LL n = 0;
	for (int i = 0; i < num.length(); i++) {
		n = n * radix + Char2Int(num[i]);
		if (n < 0) return MAX;
	}
	return n;
}

int FindMinRadix(const string& n)
{
	int maxDigit = 0;
	for (int i = 0; i < n.length(); i++)
		maxDigit = max(maxDigit, Char2Int(n[i]));
	return maxDigit + 1;
}

LL BinarySearch(LL decN1, const string& n2)
{
	LL low = FindMinRadix(n2);
	LL high = decN1 + 1;
	LL mid, minRadix = high;
	bool ok = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		LL decN2 = ToDec(n2, mid);
		if (decN1 < decN2)
			high = mid - 1;
		else if (decN1 > decN2)
			low = mid + 1;
		else {
			minRadix = min(minRadix, mid);
			high = mid - 1;
			ok = 1;
		}
	}

	if (ok) return minRadix;
	else return -1;
}

int main()
{
	//freopen("in", "r", stdin);

	string n1, n2;
	int tag, radix;

	cin >> n1 >> n2 >> tag >> radix;

	if (tag == 2)
		swap(n1, n2);

	int r = BinarySearch(ToDec(n1, radix), n2);

	if (r == -1) 
		cout << "Impossible" << endl;
	else
		cout << r << endl;

	return 0;
}