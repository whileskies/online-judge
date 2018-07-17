#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10005;
vector<int> G[maxn];
set<int> S;
int p[maxn], N;
bool vis[maxn];
int maxD;   

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void findDeepest(int u, int d)
{
	if (d > maxD) {
		S.clear();
		S.insert(u);
		maxD = d;
	} else if (d == maxD)
		S.insert(u);

	for (int i = 0; i < G[u].size(); i++) {
		if (!vis[G[u][i]]) {
			vis[G[u][i]] = 1;
			findDeepest(G[u][i], d+1);
			vis[G[u][i]] = 0;
		}
	}
}

int main()
{
	//freopen("in", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; i++)
		p[i] = i;
	for (int i = 1; i <= N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		p[find(u)] = find(v);
	}

	int components = 0;
	for (int i = 1; i <= N; i++)
		if (p[i] == i)
			components++;
	if (components > 1) 
		cout << "Error: " << components << " components" << endl;
	else {
		memset(vis, 0, sizeof(vis));
		vis[1] = 1; maxD = -1;
		findDeepest(1, 0);
		set<int> tmp = S;
		memset(vis, 0, sizeof(vis));
		vis[*S.begin()] = 1; maxD = -1;
		findDeepest(*S.begin(), 0);
		for (auto e : tmp) S.insert(e);
		for (auto e : S) cout << e << endl;
	}

	return 0;
}