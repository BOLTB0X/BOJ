#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void DFS(int n, int m, vector<int>& per,int level) {
	if (level == m) {
		for (int& p : per)
			cout << p << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i) {
		per.push_back(v[i]);
		DFS(n, m, per, level + 1);
		per.pop_back();
	}
	return;
}

void solution(int n, int m) {
	sort(v.begin(), v.end()); // 오름차순 정렬

	vector<int> per;
	DFS(n, m, per, 0); 
	return;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	solution(n, m);
	return 0;
}
