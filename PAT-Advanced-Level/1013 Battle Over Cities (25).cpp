#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 1010;
int N, M, K;

struct Eage
{
	Eage(int _u, int _v) : u(_u), v(_v) {}
	int u, v;
};

vector<Eage> eages;
int p[maxN];

int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}


int main()
{
	//freopen("in", "r", stdin);

	cin >> N >> M >> K;

	while (M--) {
		int u, v;
		cin >> u >> v;
		eages.push_back(Eage(u, v));
	}

	while (K--) {
		int except;
		int cnt = 0;

		for (int i = 1; i <= N; i++)
			p[i] = i;

		cin >> except;
		for (int i = 0; i != eages.size(); i++) {
			if (eages[i].u == except || eages[i].v == except)
				continue;
			int u = eages[i].u, v = eages[i].v;
			p[find(u)] = find(v);
		}

		for (int i = 1; i <= N; i++) {
			if (p[i] == i)
				cnt++;
		}
		cout << cnt - 2 << endl;  //去掉except结点，再-1
	}


	return 0;
}