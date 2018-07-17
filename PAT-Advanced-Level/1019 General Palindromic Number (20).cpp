#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> convert(int n, int base)
{
	stack<int> ret;
	while (n) {
		ret.push(n % base);
		n /= base;
	}
	return ret;
}

bool isPalindromic(stack<int> n)
{
	stack<int> r, ori = n;
	while (!n.empty()) {
		r.push(n.top());
		n.pop();
	}
	return r == ori;
}

int main()
{
	//freopen("in", "r", stdin);

	int N, b;
	stack<int> ret;

	cin >> N >> b;
	ret = convert(N, b);

	if (isPalindromic(ret)) cout << "Yes" << endl;
	else cout << "No" << endl;

	if (ret.empty()) cout << "0";
	else {
		cout << ret.top();
		ret.pop();
		while (!ret.empty()) {
			cout << " " << ret.top();
			ret.pop();
		}
	}

	return 0;
}