#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("in", "r", stdin);

	int N;
	int prefloor = 0, nowfloor;
	int time = 0;

	cin >> N;
	while (N--) {
		cin >> nowfloor;
		if (nowfloor > prefloor) {
			time += (nowfloor - prefloor)*6;
			time += 5;
		}
		else if (nowfloor < prefloor) {
			time += (prefloor - nowfloor)*4;
			time += 5;
		}
		else
			time += 5;
		prefloor = nowfloor;
	}

	cout << time;

	return 0;
}