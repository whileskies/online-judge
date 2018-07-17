#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Test
{
	string id;
	int score;
	int locaNum;
	int rank[2];
	Test(string _id, int _score, int _locaNum) : 
	id(_id), score(_score), locaNum(_locaNum) {}
};

bool cmp(Test &a, Test &b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.id < b.id;
}

vector<Test> all;
int N, K;

void getRank(vector<Test> &vec, int t) {
	sort(vec.begin(), vec.end(), cmp);
	int rank = 1, lastScore = -1;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].score != lastScore) {
			rank = i+1;
			vec[i].rank[t] = rank;
		} else {
			vec[i].rank[t] = rank;
		}
		lastScore = vec[i].score;
	}
}

int main()
{
	//freopen("in", "r", stdin);

	cin >> N;
	for (int l = 1; l <= N; l++) {
		vector<Test> vec;
		cin >> K;
		while (K--) {
			string id;
			int score;
			cin >> id >> score;
			vec.push_back(Test(id, score, l));
		}
		getRank(vec, 1);
		for (auto &e : vec) {
			all.push_back(e);
		}
	}
	getRank(all, 0);
	cout << all.size() << endl;
	for (auto &e : all) {
		cout << e.id << " " << e.rank[0] << " "
			 << e.locaNum << " " << e.rank[1] << endl;
	}

	return 0;
}