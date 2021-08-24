#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
int visited[101] = { 0, };
int min_value = 0x7fffffff;
int result;

int min(int a, int b) {
	return a < b ? a : b;
}

//방문 초기화
void init() {
	//각 노드 별 거리정보 초기화
	for (int i = 1; i <= n; i++) 
		visited[i] = 0;

}

void BFS(int start) {
	queue<int> q;
	visited[start] = 1;
	q.push(start);

	//큐가 빌때까지
	//정점별 각 방문거리 저장
	while (!q.empty()) {
		start = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			//스타트 행의 열이 있고 방문한적이 없다면
			if (map[start][i] == 1 && visited[i] == 0) {
				visited[i] = visited[start] + 1;
				//다음 출발정점 큐의 삽입
				q.push(i);
			}
		}
	}
}

//최소 방문길이를 가진 정점 찾기
void find_min_vertex(int start) {
	int tmp_tot = 0;
	//각 visited 에 스타트에서 정점별 걸리가 담겼음
	for (int j = 1; j <= n; j++) {
		// 자기 자신은 생략
		if (start == j) continue;
		//첨 시작을 1로 했으므로
		tmp_tot += (visited[j] - 1);
	}
	if (tmp_tot < min_value) {
		min_value = tmp_tot;
		result = start;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		//2차 행렬에 체크
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	for (int start = 1; start <= n; start++) {
		init();
		BFS(start);
		find_min_vertex(start);
	}

	cout << result << '\n';
	return 0;
}