#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxV = 550;
int numV, numE;
int G[maxV][maxV];
int teamCnt[maxV];
int src, dst;
int d[maxV], n[maxV], w[maxV];
bool inS[maxV];

void dijkstra()
{
	for (int u = 0; u < numV; u++) {
		d[u] = INF;
		w[u] = INF;
		n[u] = 0;
	}

	d[src] = 0;
	n[src] = 1;
	w[src] = teamCnt[src];

	for (int i = 0; i < numV; i++) {
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
			if (!inS[v] && G[u][v] < INF) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					n[v] = n[u];
					w[v] = w[u] + teamCnt[v];
				}
				else if (d[v] == d[u] + G[u][v]) {
					n[v] = n[u] + n[v];
					if (w[v] < w[u] + teamCnt[v])
						w[v] = w[u] + teamCnt[v];
				}
			}
		}
	}
}



int main()
{
	//freopen("in", "r", stdin);

	memset(G, 0x3f, sizeof(G));
	cin >> numV >> numE >> src >> dst;
	for (int i = 0; i < numV; i++)
		cin >> teamCnt[i];
	for (int i = 0; i < numE; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u][v] = w;
		G[v][u] = w;
	}

	dijkstra();
	cout << n[dst] << " " << w[dst];
	
	return 0;
}
