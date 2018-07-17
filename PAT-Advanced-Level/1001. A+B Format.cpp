#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("in", "r", stdin);

	int a, b, sum;
	stack<char> digit;
	int flag = 0;

	cin >> a >> b;
	sum = a + b;

	if (sum < 0) {
		flag = 1;
		sum = -sum;
	}

	if (sum == 0)
		digit.push('0');

	int cnt = 0;
	while (sum) {
		digit.push(sum % 10 + '0');
		cnt++;
		sum /= 10;
		if (cnt % 3 == 0 && sum)
			digit.push(',');
	}


	if (flag) digit.push('-');

	while (!digit.empty()) {
		cout << digit.top();
		digit.pop();
	}

	return 0;
}