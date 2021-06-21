#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> map[2001];
bool visited[2001];
int answer=0;

void dfs(int cur, int dep) {
	visited[cur] = true;
	if (dep == 4) {
		answer = 1;
		return;
	}
	for (int i = 0; i < map[cur].size(); i++) {
		int next = map[cur][i];
		if (!visited[next]) {
			dfs(next, dep + 1);
			visited[next] = false;
		}
	}
}

int main(void) {
	int result = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		dfs(i, 0);
		visited[i] = false;
		if (answer==1)
			break;
	}
	if (answer!=0) cout << '1';
	else cout << '0';
	return 0;
}