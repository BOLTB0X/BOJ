#include <iostream>
#include <vector>

using namespace std;

vector<int> per;
bool visited[9] = { false, };

//백트래킹 
void DFS(int n, int m, int depth) {
	if (depth == m) {
		for (int i = 0; i < per.size(); i++) {
			cout << per[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		per.push_back(i);
		DFS(n, m, depth + 1);
		per.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;

	cin >> n >> m;
	DFS(n, m, 0);
	return 0;
}
