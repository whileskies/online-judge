#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 550;
const int INF = 0x3f3f3f3f;
int E[MAXN][MAXN];
int N, M, maxC, dst;
int C[MAXN], dis[MAXN];
bool inS[MAXN];
int minSend = INF, minBack = INF;
vector<int> path[MAXN];
vector<int> retPath, tempPath;

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	
	dis[s] = 0;
	path[s].push_back(s);

	for (int i = 0; i < N; i++) {
		int u = -1, Min = INF;
		for (int v = 0; v < N; v++) {
			if (!inS[v] && dis[v] < Min) {
				Min = dis[v];
				u = v;
			}
		}

		if (u == -1) break;
		inS[u] = 1;

		for (int v = 0; v < N; v++) {
			if (!inS[v] && E[u][v] < INF) {
				if (dis[v] > dis[u] + E[u][v]) {
					dis[v] = dis[u] + E[u][v];
					path[v].clear();
					path[v].push_back(u);
				} else if (dis[v] == dis[u] + E[u][v])
					path[v].push_back(u);
			}
		}
	}
}

void dfs(int u)
{
	if (u == 0) {
		int send = 0, back = 0;
		for (int i = tempPath.size()-1; i >= 0; i--) {
			int r = C[tempPath[i]] - maxC/2;
			if (r >= 0) back += r;
			else {
				r = -r;
				if (back >= r) back -= r;
				else {
					send += r - back;
					back = 0;
				}
			}
		}
		if (send < minSend) {
			minSend = send;
			minBack = back;
			retPath = tempPath;
		} else if (send == minSend && back < minBack) {
			minBack = back;
			retPath = tempPath;
		}
		return;
	}

	tempPath.push_back(u);
	for (int i = 0; i < path[u].size(); i++)
		dfs(path[u][i]);
	tempPath.pop_back();
}

int main()
{
	//freopen("in", "r", stdin);

	cin >> maxC >> N >> dst >> M;
	for (int i = 1; i <= N; i++)
		cin >> C[i];
	memset(E, 0x3f, sizeof(E));
	for (int i = 0; i < M; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		E[u][v] = E[v][u] = t;
	}
	N++;

	dijkstra(0);
	dfs(dst);

	cout << minSend << " 0";
	for (int i = retPath.size()-1; i >= 0; i--)
		cout << "->" << retPath[i];
	cout << " " << minBack << endl; 

	return 0;
}