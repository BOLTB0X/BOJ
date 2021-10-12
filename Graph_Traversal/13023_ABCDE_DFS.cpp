#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[2001];
bool visited[2001];
//체크
bool flag = false;

//입력
void input(void) {
	cin >> N >> M;
	//노드 갯수만큼 반복
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	return;
}

//깊이 우선
void DFS(int start, int depth) {
	visited[start] = true;
	
	//즉 친구관계 A,B,C,D,E 깊이가 4이므로
	if (depth == 4) {
		flag = true;
		return;
	}
	for (int i = 0; i < graph[start].size(); ++i) {
		int next = graph[start][i];
		if (!visited[next]) {
			DFS(next, depth + 1);
			visited[next] = false;
		}
	}
	return;
}

//해결
void solution(void) {
	//입력
	input();
	//각 정점별 탐색
	for (int i = 0; i < N; ++i) {
		DFS(i, 0);
		visited[i] = false;
		if (flag)
			break;
	}
	cout << flag << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
