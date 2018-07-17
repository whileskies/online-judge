#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int n, m;
map<string, set<int>> titleMap;
map<string, set<int>> authorMap;
map<string, set<int>> keyMap;
map<string, set<int>> publisherMap;
map<string, set<int>> yearMap; 

void query(map<string, set<int>> &M, string key) {
	if (M.find(key) == M.end())
		printf("Not Found\n");
	else {
		set<int> s = M[key];
		for (auto it = s.begin(); it != s.end(); it++)
			printf("%07d\n", *it);
	}
}

int main()
{
	//freopen("in", "r", stdin);

	scanf("%d\n", &n);
	while (n--) {
		int id, year;
		string s;
		scanf("%d\n", &id);
		getline(cin, s);
		titleMap[s].insert(id);
		getline(cin, s);
		authorMap[s].insert(id);
		getline(cin, s);
		stringstream ss(s);
		while (ss >> s)
			keyMap[s].insert(id);
		getline(cin, s);
		publisherMap[s].insert(id);
		getline(cin, s);
		yearMap[s].insert(id);
	}

	scanf("%d\n", &m);
	while (m--) {
		int op;
		string s, key;
		getline(cin, s);
		cout << s << endl;
		op = s[0] - '0';
		key = s.substr(3, s.length());
		if (op == 1) query(titleMap, key);
		if (op == 2) query(authorMap, key);
		if (op == 3) query(keyMap, key);
		if (op == 4) query(publisherMap, key);
		if (op == 5) query(yearMap, key);
	}

	return 0;
}