#include <iostream>

using namespace std;

int n, result;

//다 탐색 되었는지 체크함수
bool check(bool* visited) {
	for (int i = 1; i < n; i++) {
		if (!visited[i])
			return false;
	}
	return true;
}

//깊이 우선 탐색
void DFS(int (*graph)[11], bool* visited, int tot, int depth) {
	//모든 정점 탐색했다면
	if (check(visited)) {
		//마지막 위치 연산
		if (graph[depth][0] != 0) {
			tot += graph[depth][0];
			//최소값 조건이 되면
			if (tot < result)
				result = tot;
		}
		return;
	}
	//연결된 정점 탐색
	for (int i = 1; i < n; i++) {
		//그래프가 0이 아니고 미방문이면
		if (graph[depth][i] != 0 && !visited[i]) {
			visited[i] = true;
			DFS(graph, visited, tot + graph[depth][i], i);
			visited[i] = false;
		}
	}
}

//해결함수
void solution(int(*graph)[11], bool* visited) {
	//해결
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> graph[y][x];
		}
	}
	//결과 셋팅
	result = 987654321;
	//각 정점 탐색시작
	DFS(graph, visited, 0, 0);
	cout << result << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int graph[11][11];
	bool visited[11] = { false, };

	//솔루션시작
	solution(graph, visited);
	
	return 0;
}