#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//구조체
struct INF {
	int y, x, cnt;
};

const int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
const int dx[8] = { -2,-1,1,2,2,1,-1,-2 };

//너비우선탐색
void BFS(vector<vector<bool>> &visited, int n, int sy, int sx, int ty, int tx) {
	//큐 선언
	queue<INF> q;
	q.push({ sy,sx,0 });
	visited[sy][sx] = true;

	while (!q.empty()) {
		INF cur = q.front();
		q.pop();

		//탈출조건
		if (cur.y == ty && cur.x == tx) {
			cout << cur.cnt << '\n';
			return;
		}
		
		//이동방향 차례로
		for (int dir = 0; dir < 8; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			
			//재방문
			if (visited[ny][nx] == true)
				continue;

			q.push({ ny,nx,cur.cnt + 1 });
			visited[ny][nx] = true;
		}
	}

	return;
}

void solution(void) {
	int T;
	cin >> T;
	
	while (T--) {
		int n;
		int sy, sx, ty, tx;
		vector<vector<bool>> visited;

		cin >> n;
		//벡터 초기화
		visited.resize(n, vector<bool>(n, false));
		
		//스타트, 목적지
		cin >> sy >> sx;
		cin >> ty >> tx;
		
		//너비우선탐색 호출
		BFS(visited, n, sy, sx, ty, tx);;
	}

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