#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string unlock_ID_number, lock_ID_num;

struct Time
{
	int h, m, s;
	Time(int _h, int _m, int _s):
		h(_h), m(_m), s(_s) {}

	bool operator<(const Time &rhs) {
		if (h < rhs.h)
			return 1;
		if (h == rhs.h && m < rhs.m)
			return 1;
		if (h == rhs.h && m == rhs.m
					   && s < rhs.s)
			return 1;
		return 0;
	}
};

int main()
{
	//freopen("in", "r", stdin);
	int M;
	string ID_number;
	Time min_unlock_time(23, 59, 59);
	Time max_lock_time(0, 0, 0);

	cin >> M;
	while (M--) {
		char ch;
		int h, m, s;

		cin >> ID_number;
		cin >> h >> ch >> m >> ch >> s;
		Time in(h, m, s);
		if (in < min_unlock_time) {
			min_unlock_time = in;
			unlock_ID_number = ID_number;
		}

		cin >> h >> ch >> m >> ch >> s;
		Time out(h, m, s);
		if (! (out < max_lock_time) ) {
			max_lock_time = out;
			lock_ID_num = ID_number;
		}
	}

	cout << unlock_ID_number << " " << lock_ID_num;

	return 0;
}