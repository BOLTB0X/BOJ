#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct Shark{
	int y, x, dist;

	bool operator < (const Shark& s) const {
		if (dist == s.dist) {
			if (y == s.y)
				return x > s.x;
			return y > s.y;
		}
		return dist > s.dist;
	}
};

int n;
int board[20][20];
bool visited[20][20]; // 방문리스트
priority_queue<Shark> pq; // 우선순위 큐

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int BFS(void) {
	int shark_size = 2; // 초기
	int shark_move = 0;
	int eating_cnt = 0;

	while (!pq.empty()) {
		int cy = pq.top().y;
		int cx = pq.top().x;
		int cd = pq.top().dist;
		pq.pop();

		// 현재 물고기가 있다면
		if (board[cy][cx] > 0) {
			// 크기 비교
			if (shark_size > board[cy][cx]) {
				eating_cnt++;
				board[cy][cx] = 0;
				
				// 사이즈 업가능 하면
				if (eating_cnt == shark_size) {
					shark_size++;
					eating_cnt = 0; // 초기화
				}

				shark_move += cd; // 총 이동횟수 카운트
				memset(visited, 0, sizeof(visited)); // 초기화
				while (!pq.empty()) // 큐 비우기
					pq.pop();
				cd = 0; // 이동거리 초기화
			}
		}

		// 순차적으로 상하좌우 확인
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			// 범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			// 재방문
			if (visited[ny][nx])
				continue;

			// 사이즈가 크면
			if (board[ny][nx] > shark_size)
				continue;

			pq.push({ ny,nx,cd + 1 });
			visited[ny][nx] = 1;
		}
	}

	return shark_move;
}

int solution(void) {
	int answer = 0;
	memset(visited, 0, sizeof(visited)); // 방문리스트 초기화

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// 아기 상어 발견
			if (board[i][j] == 9) {
				pq.push({ i,j,0 });
				board[i][j] = 0; // 빈 공간처리
			}
		}
	}

	answer = BFS();
	return answer;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	}

	int ret = solution();
	cout << ret;
	return 0;
}
