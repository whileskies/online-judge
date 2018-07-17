#include <iostream>
#include <map>
#include <vector>
#include <typeinfo>
#include <algorithm>

using namespace std;

struct student
{
	student(int c, int m, int e) {
		score[0] = c;
		score[1] = m;
		score[2] = e;
		score[3] = (c + m + e + 0.5) / 3.0;
	}

	int score[4];
	int rank[4];
};

int tag = 0;
bool cmp(const pair<int, student>& p1, const pair<int, student>& p2)
{
	return p1.second.score[tag] > p2.second.score[tag];
}

map<int, student> stuMap;
const char Convert[4] = {'C', 'M', 'E', 'A'};

int main()
{
	//freopen("in", "r", stdin);

	int N, M;

	cin >> N >> M;
	while (N--) {
		int ID, c, m, e;
		cin >> ID >> c >> m >> e;
		stuMap.insert(pair<int, student>(ID, student(c, m, e)));
	}

	vector<pair<int, student>> stuVec(stuMap.begin(), stuMap.end());

	for (int i = 0; i < 4; i++) {
		tag = i;
		sort(stuVec.begin(), stuVec.end(), cmp);

		int r = 1;
		stuMap.find(stuVec[0].first)->second.rank[i] = r;

		for (size_t j = 1; j < stuVec.size(); j++) {
			if (stuVec[j].second.score[i] != stuVec[j-1].second.score[i]) 
				r = j + 1;
			stuMap.find(stuVec[j].first)->second.rank[i] = r;
		}
	}

	while (M--) {
		int ID;
		cin >> ID;

		if (stuMap.find(ID) == stuMap.end())
			cout << "N/A" << endl;
		else {
			student s = stuMap.find(ID)->second;
			int minRank = s.rank[3];
			int index = 3;
			for (int i = 0; i < 3; i++) {
				if (s.rank[i] < minRank) {
					minRank = s.rank[i];
					index = i;
				}
			}
			cout << minRank << " " << Convert[index] << endl;
		}
	}

	return 0;
}