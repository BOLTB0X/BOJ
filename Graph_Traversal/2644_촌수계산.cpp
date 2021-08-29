#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
bool visited[101];
int result=-1;

void DFS(int start, int target, int cnt) {
	visited[start] = true;
	if (start == target) {
		result = cnt;
		return;
	}
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next]) 
			DFS(next, target, cnt+1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	int start, target;

	cin >> n;
	cin >> start >> target;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	DFS(start, target, 0);
	cout << result << '\n';
	return 0;
}