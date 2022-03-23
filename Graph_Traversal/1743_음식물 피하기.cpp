#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> visited;
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };
int result;

void DFS(int n, int m, int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			continue;

		if (visited[ny][nx] == 1 || adj[ny][nx] == 0)
			continue;
		
		result++; // dfs 호출 횟수가 뭉쳐있는 음식물의 크기
		visited[ny][nx] = 1;
		DFS(n, m, ny, nx);
	}

	return;
}

int solution(int n, int m, int k) {
	int answer = 0;
	// 음식물중 제일 큰 음식물을 구해야함
	// 음식물들은 근처에 있는 것끼리 뭉치게 돼서 큰 음식물 쓰레기가 된다.
	
	visited.resize(n + 1, vector<int>(m + 1, 0)); // 재정의

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			// 미방문이고 음식물 발견
			if (visited[i][j] == 0 && adj[i][j] == 1) {
				result = 1; // 초기화
				visited[i][j] = 1; // 방문처리
				DFS(n, m, i, j);

				// 최댓값 교체
				if (answer < result)
					answer = result;
			}
		}
	}
	return answer;
}

int main(void) {
	int n, m, k;
	int a, b;
	cin >> n >> m >> k;
	adj.resize(n + 1, vector<int>(m + 1, 0)); // 재정의

	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		
		adj[a][b] = 1;
	}

	int ret = solution(n, m, k);
	cout << ret;

	return 0;
}