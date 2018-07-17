#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string doubleN(string n) {
	int carry = 0;
	for (int i = n.length()-1; i >= 0; i--) {
		int b = (n[i]-'0')*2 + carry;
		n[i] = b%10 + '0';
		carry = b/10 ;
	}
	if (carry) return string(1, carry+'0') + n;
	else return n;
}

bool isPermutation(string n, string twiceN) {
	int cnt1[10] = {0}, cnt2[10] = {0};
	for (int i = 0; i < n.length(); i++)
		cnt1[n[i]-'0']++;
	for (int i = 0; i < twiceN.length(); i++)
		cnt2[twiceN[i]-'0']++;
	for (int i = 0; i <= 9; i++) {
		if (cnt1[i] != cnt2[i])
			return 0;
	}
	return 1;
}

int main()
{
	//freopen("in", "r", stdin);

	string n, twiceN;

	cin >> n;
	twiceN = doubleN(n);

	if (isPermutation(n, twiceN))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << twiceN << endl;

	return 0;
}