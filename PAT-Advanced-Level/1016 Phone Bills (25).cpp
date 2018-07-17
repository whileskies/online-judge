#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Time
{
	int m, d, h, min;
	Time(int _m, int _d, int _h, int _min) : 
		m(_m), d(_d), h(_h), min(_min) {}
	bool operator< (const Time& rhs) {
		if (m < rhs.m)
			return 1;
		if (m == rhs.m && d < rhs.d)
			return 1;
		if (m == rhs.m && d == rhs.d && h < rhs.h)
			return 1;
		if (m == rhs.m && d == rhs.d && h == rhs.h
			&& min < rhs.min)
			return 1;
		return 0;
	}

	void print() const {
		cout.fill('0');
		cout << setw(2) << d << ":" << setw(2) 
			 << h << ":" << setw(2) << min << " ";
	}
};

struct Record
{
	string name;
	Time t;
	bool stat;
	Record(const string& _name, const Time& _t, bool _stat) : 
		name(_name), t(_t), stat(_stat) {}
};

bool cmp(Record& lhs, Record& rhs) {
	if (lhs.name == rhs.name)
		return lhs.t < rhs.t;
	return lhs.name < rhs.name;
}

int Month, N;
double Rate[25];
vector<Record> records;
map<string, vector< pair<Time, Time> > > billMap;

void calPeriodCharge(pair<Time, Time> t, int& period, double& charge)
{
	Time t1 = t.first, t2 = t.second;
	while (t1.d < t2.d || t1.h < t2.h || t1.min < t2.min) {
		period ++;
		t1.min ++;
		charge += Rate[t1.h];
		if (t1.min == 60)
			t1.min = 0, t1.h++;
		if (t1.h == 24)
			t1.h = 0, t1.d++;
	}
}

int main()
{
	//freopen("in", "r", stdin);

	for (int i = 0; i < 24; i++) {
		cin >> Rate[i];
		Rate[i] /= 100;
	}
	cin >> N;

	while (N--) {
		string name, strStat;
		int m, d, h, min;
		char ch;
		bool stat;

		cin >> name >> m >> ch >> d >> ch
			>> h >> ch >> min >> strStat;
		Month = m;
		Time t(m, d, h, min);
		if (strStat == "on-line")
			records.push_back(Record(name, t, 1));
		else 
			records.push_back(Record(name, t, 0));
	}

	sort(records.begin(), records.end(), cmp);

	vector<Record>::iterator it;
	for (it = records.begin(); it != records.end()-1; it++)
	{	
		string name;
		Record record1 = *it, record2 = *(it + 1);
		if (record1.name == record2.name && record1.stat == 1 
			&& record2.stat == 0) {
			name = record1.name;
			if (billMap.find(name) != billMap.end()) {
				billMap.find(name)->second.push_back(pair<Time, Time> (record1.t, record2.t));
			} else {
				vector<pair<Time, Time> > vec;
				vec.push_back(pair<Time, Time> (record1.t, record2.t));
				billMap[name] = vec;
			}
		}
	}

	for (auto& bill : billMap) {
		cout.fill('0');
		cout << bill.first << " " << setw(2) << Month << endl;
		double total = 0;
		for (auto& r : bill.second) {
			int period = 0;
			double charge = 0;
			calPeriodCharge(r, period, charge);
			r.first.print(); r.second.print();
			cout << period << " $" ;
			cout << setiosflags(ios::fixed) << setprecision(2) << charge << endl;
			total += charge;
		}
		cout << "Total amount: $" << total << endl;
	}

	return 0;
}