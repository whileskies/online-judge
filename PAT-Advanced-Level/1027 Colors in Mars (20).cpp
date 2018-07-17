#include <iostream>

using namespace std;

const char D[13] = {'0', '1', '2', '3', '4',
	'5', '6', '7', '8', '9', 'A', 'B', 'C'};
string to13(int n)
{
	if (n == 0) return "00";
	string ret;
	while (n) {
		ret = string(1, D[n % 13]) + ret;
		n /= 13;
	}
	if (ret.length() == 1)
		ret = "0" + ret;
	return ret;
}

int main()
{
	//freopen("in", "r", stdin);

	int r, g, b;

	cin >> r >> g >> b;
	cout << "#" << to13(r) << to13(g) << to13(b) << endl;

	return 0;
}