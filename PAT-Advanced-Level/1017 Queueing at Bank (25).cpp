#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Customer
{
	int h, m, s, t;

	Customer(int _h, int _m, int _s, int _t) : 
				h(_h), m(_m), s(_s), t(_t) {}

	bool operator< (const Customer& rhs) {
		if (h != rhs.h) return h < rhs.h;
		else if (m != rhs.m) return m < rhs.m;
		else return s < rhs.s;
	}

	int toS() const {
		return h*60*60 + m*60 + s;
	}
};

int N, K, leave[10010], cnt;
vector<Customer> cus;
vector<int> inService(101, -1);
double sum = 0;

int main()
{
	//freopen("in", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int h, m, s, t;
		char ch;

		cin >> h >> ch >> m >> ch >> s >> t;
		cus.push_back(Customer(h, m, s, t*60));
	}

	sort(cus.begin(), cus.end());
    
	for (int i = 0; i < N; i++) {
		if (cus[i].toS() >= 17*60*60 + 1)
			break;
		cnt++;
		bool hasVancy = 0;
		int index = 0;

		for (int j = 0; j < K; j++) {
			if (inService[j] != -1 && 
				leave[inService[j]] <= cus[i].toS())
				inService[j] = -1;
			if (inService[j] == -1) {
				hasVancy = 1;
				index = j;
			}
		}

		if (hasVancy) {
			if (cus[i].toS() <= 8*60*60) 
				leave[i] = 8*60*60 + cus[i].t;		
			else leave[i] = cus[i].toS() + cus[i].t;
		}
		else {
			int minTime = 1<<30;
			for (int j = 0; j < K; j++) {
				if (leave[inService[j]] < minTime) {
					minTime = leave[inService[j]];
					index = j;
				}
			}
			leave[i] = leave[inService[index]] + cus[i].t;
		}
		inService[index] = i;
		sum += leave[i] - cus[i].toS() - cus[i].t;
	}

	cout << fixed << setprecision(1) << sum/cnt/60.0 << endl;

	return 0;
}