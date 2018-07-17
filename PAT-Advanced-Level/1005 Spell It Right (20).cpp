#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

const string english[12] = {"zero", "one",
	"two", "three", "four", "five", "six",
	"seven", "eight", "nine", "ten" };

int main()
{
	//freopen("in", "r", stdin);

	char ch;
	int sum = 0;
	stack<int> digit;

	while (cin >> ch) {
		sum += (ch - '0');
	}

	while (sum) {
		digit.push(sum % 10);
		sum /= 10;
	}

	if (!digit.empty()) {
		int t = digit.top();
		digit.pop();
		cout << english[t];

		while (!digit.empty()) {
		cout << " " << english[digit.top()];
		digit.pop();
		}
	}
	else
		cout << english[0];

	return 0;
}