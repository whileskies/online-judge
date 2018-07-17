#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxV = 550;
int numV, numE, s;
int E[maxV][maxV], Cost[maxV][maxV];
int d[maxV], c[maxV];
bool inS[maxV];
int path[maxV];
int src, dst;

void buildEraph()
{
	memset(E, 0x3f, sizeof(E));
	memset(Cost, 0x3f, sizeof(Cost));
	cin >> numV >> numE >> src >> dst;
	for (int i = 0; i < numE; i++) {
		int u, v, w, c;
		cin >> u >> v >> w >> c;
		E[u][v] = w;
		E[v][u] = w;
		Cost[u][v] = c;
		Cost[v][u] = c;
	}
}

void dijkstra(int s)
{
	for (int i = 0; i < numV; i++) {
		d[i] = INF;
		c[i] = INF;
		inS[i] = 0;
		path[i] = -1;
	}

	d[s] = 0;
	c[s] = 0;

	for (int i = 1; i < numV; i++) {
		int Min = INF, u = -1;
		for (int v = 0; v < numV; v++) {
			if (!inS[v] && d[v] < Min) {
				Min = d[v];
				u = v;
			}
		}

		if (u != -1)
			inS[u] = 1;
		else break;

		for (int v = 0; v < numV; v++) {
			if (!inS[v] && E[u][v] < INF) {
				if (d[v] > d[u] + E[u][v]) {
					d[v] = d[u] + E[u][v];
					c[v] = c[u] + Cost[u][v];
					path[v] = u;
				}
				else if (d[v] == d[u] + E[u][v] && c[v] > c[u] + Cost[u][v]) {
					c[v] = c[u] + Cost[u][v];
					path[v] = u;
				}
			}
		}
	}
}

void outPath(int u)
{
	if (u == -1)
		return;
	outPath(path[u]);
	cout << u << " ";
}


int main()
{
	//freopen("in", "r", stdin);

	buildEraph();
	dijkstra(src);

	outPath(dst);
	cout << d[dst] << " " << c[dst];

	return 0;
}