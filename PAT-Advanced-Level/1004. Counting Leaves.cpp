#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
vector<int> node[maxn];
int no_children[maxn];
int max_level;
int N, M;

struct queue_node
{
	int id;
	int level;
	queue_node(int _id, int _level) : 
		id(_id), level(_level) {}
};

void dfs(int u, int level)
{
	max_level = max(level, max_level);
	if (node[u].size() == 0)
		no_children[level]++;
	for (int i = 0; i < node[u].size(); i++) {
		dfs(node[u][i], level+1);
	}
}

void bfs()
{
	queue<queue_node> Q;

	Q.push(queue_node(1, 1));
	while (!Q.empty()) {
		queue_node n = Q.front();
		Q.pop();

		max_level = max(n.level, max_level);
		if (node[n.id].size() == 0)
			no_children[n.level]++;
		for (int i = 0; i < node[n.id].size(); i++) {
			Q.push(queue_node( node[n.id][i], n.level + 1 ) );
		}
	}
}


int main()
{
	freopen("in", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int ID, K, children;
		cin >> ID >> K;
		while (K--) {
			cin >> children;
			node[ID].push_back(children);
		}
	}

	//bfs();
	dfs(1, 1);

	cout << no_children[1];
	for (int i = 2; i <= max_level; i++)
		cout << " " << no_children[i];

	
	return 0;
}