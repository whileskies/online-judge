#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxV = 550;
int numV, numE;
int G[maxV][maxV];
int vis[maxV];
int teamCnt[maxV];
int src, dst;
int shortestLen = INF;

struct node
{
	int len;
	int team;
	node() {}
	node(int _len, int _team) : len(_len), team(_team) {}
};

vector<node> record;

void dfs(int u, int len, int team)
{
	if (u == dst) {
		record.push_back(node(len, team));
		shortestLen = min(shortestLen, len);
		return ;
	}

	for (int v = 0; v < numV; v++) {
		if (!vis[v] && G[u][v] < INF) {
			vis[v] = 1;
			dfs(v, len+G[u][v], team+teamCnt[v]);
			vis[v] = 0;
		}
	
	}
}

int main()
{
	//freopen("in", "r", stdin);

	memset(G, 0x3f, sizeof(G));
	memset(vis, 0, sizeof(vis));
	cin >> numV >> numE >> src >> dst;
	for (int i = 0; i < numV; i++)
		cin >> teamCnt[i];
	for (int i = 0; i < numE; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u][v] = w;
        G[v][u] = w;
	}

	dfs(src, 0, teamCnt[src]);

	int pathCnt = 0;
	int maxTeamCnt = 0;

	for (vector<node>::iterator it = record.begin(); it != record.end(); it++) {
		if (it->len == shortestLen) {
			pathCnt++;
			maxTeamCnt = max(maxTeamCnt, it->team);
		}
	}

	cout << pathCnt << " " << maxTeamCnt;

	return 0;
}
