#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseNum(string n) {
	string ret = n;
	reverse(ret.begin(), ret.end());
	return ret;
}

bool isPalindromic(string n) {
	return reverseNum(n) == n;
}

string add(string a, string b) {
	string ret;
	int carry = 0;
	int i = a.length()-1, j = b.length()-1;
	while (i >= 0 || j >= 0 || carry) {
		int bita, bitb, bit;
		bita = i >= 0 ? a[i]-'0' : 0;
		bitb = j >= 0 ? b[j]-'0' : 0;
		bit = bita + bitb + carry;
		ret = ret + string(1, bit%10 + '0');
		carry = bit/10;
		i--; j--;
	}
	return reverseNum(ret);
}

int main()
{
	//freopen("in", "r", stdin);
	string N;
	int K, cnt = 1;

	cin >> N >> K;

	while (cnt <= K) {
		if (isPalindromic(N)) {
			break;
		} else {
			N = add(N, reverseNum(N));
			cnt++;
		}
	}

	cout << N << endl;
	cout << cnt-1 << endl;


	return 0;
}