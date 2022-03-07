#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int graph[51][51];
bool visited[51][51] = { false, };

// 우,하,좌,상,우상,우하,좌상,좌하
const int dy[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
const int dx[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };

//깊이 우선 탐색
void DFS(int y, int x) {
	visited[y][x] = true;
	
	//차례로 이동방향 탐색
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		//범위 초과
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;
		//재방문 및 벽인 경우
		if (visited[ny][nx] || graph[ny][nx] == 0)
			continue;

		//방문체크
		visited[ny][nx] = true;
		DFS(ny, nx);
	}
}

void solution(void) {
	int answer = 0;

	while (true) {
		cin >> m >> n;

		//종료조건
		if (n == 0 && m == 0) 
			break;
		
		else {
			//섬의 개수 초기화
			answer = 0;
			//그래프 생성
			for (int y = 0; y < n; ++y) {
				for (int x = 0; x < m; ++x) 
					cin >> graph[y][x];
			}
			
			//그래프 탐색
			for (int y = 0; y < n; ++y) {
				for (int x = 0; x < m; ++x) {
					if (graph[y][x] == 1 && !visited[y][x]) {
						answer++;
						DFS(y, x);
					}
				}
			}
			
			//출력
			cout << answer << '\n';
			
			//방문리스트 초기화
			memset(visited, false, sizeof(visited));
			answer = 0;
		}
	}
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}