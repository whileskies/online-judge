#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define Tree TreeNode*
struct TreeNode
{
	int data;
	Tree lChild;
	Tree rChild;
	TreeNode(int d, Tree l = NULL, Tree r = NULL):
		data(d), lChild(l), rChild(r) {}
};

int inOrder[35], postOrder[35];

Tree reBuildTree(int inL, int inR, int postL, int postR)
{
	if (inL > inR)
		return NULL;
	int r = postOrder[postR], rIn;
		Tree T = new TreeNode(r);
	for (int i = inL; i <= inR; i++)
		if (inOrder[i] == r) {
			rIn = i;
			break;
		}
	int postLlast = postL + rIn - inL - 1;
	T->lChild = reBuildTree(inL, rIn-1, postL, postLlast);
	T->rChild = reBuildTree(rIn+1, inR, postLlast+1, postR-1);
	return T;
}

void levelOrder(Tree r)
{
	queue<Tree> Q;
	bool flag = 0;
	if (r) Q.push(r);
	while (!Q.empty()) {
		r = Q.front(); Q.pop();
		if (!flag) {
			cout << r->data ;
			flag = 1;
		} else
			cout << " " << r->data;
		if (r->lChild) Q.push(r->lChild);
		if (r->rChild) Q.push(r->rChild);
	}
}

int main()
{
	//freopen("in", "r", stdin);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> postOrder[i];
	for (int i = 0; i < N; i++)
		cin >> inOrder[i];

	Tree T = reBuildTree(0, N-1, 0, N-1);
	levelOrder(T);

	return 0;
}