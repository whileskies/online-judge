#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
	//freopen("in", "r", stdin);

	int n, x;

	for (int i = 0; i < 2; i++) {
		scanf("%d", &n);
		while (n--) {
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
	}
	
	sort(v.begin(), v.end());

	printf("%d\n", v[(v.size()-1)/2]);

	return 0;
}