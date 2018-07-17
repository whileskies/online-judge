#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student
{
	char name[10];
	int id, grade;
	Student(int _id, char* _name, int _grade):id(_id), 
				grade(_grade) { strcpy(name, _name); }
	void print() {
		printf("%06d %s %d\n", id, name, grade);
	}
};

bool cmp1(Student &a, Student &b) { return a.id < b.id; }
bool cmp2(Student &a, Student &b) { 
	int cmp = strcmp(a.name, b.name);
	if (cmp == 0)
		return a.id < b.id;
	else 
		return cmp < 0; 
}
bool cmp3(Student &a, Student &b) { 
	if (a.grade == b.grade)
		return a.id < b.id;
	else
		return a.grade < b.grade; 
}

vector<Student> S;

int main()
{
	//freopen("in", "r", stdin);

	int N, C;

	scanf("%d %d", &N, &C);
	while (N--) {
		char name[10];
		int grade, id;
		scanf("%d %s %d", &id, name, &grade);
		S.push_back(Student(id, name, grade));
	}

	if (C == 1) sort(S.begin(), S.end(), cmp1);
	if (C == 2) sort(S.begin(), S.end(), cmp2);
	if (C == 3) sort(S.begin(), S.end(), cmp3);

	for (auto it = S.begin(); it != S.end(); it++)
		it->print();

	return 0;
}