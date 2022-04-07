#include <iostream>
#include <queue>

using namespace std;

// 아기상어
struct Shark {
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

priority_queue<Shark> pq; // 우선순위 큐
bool visited[21][21]; // 방문리스트

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// 초기화
void init(int n) {
	while (!pq.empty())
		pq.pop();

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			visited[i][j] = 0;
	return;
}

int BFS(int n, vector<vector<int>>& board) {
	int shark_size = 2; // 초기
	int shark_move = 0;
	int eating_cnt = 0;

	while (!pq.empty()) {
		int cy = pq.top().y;
		int cx = pq.top().x;
		int cd = pq.top().dist;
		pq.pop();

		// 격자판에 물고기가 있다면
		if (board[cy][cx] > 0) {
			// 잡아 먹을 수 있다면
			if (shark_size > board[cy][cx]) {
				eating_cnt++;
				board[cy][cx] = 0;

				// 몸집 증가
				if (eating_cnt == shark_size) {
					shark_size++;
					eating_cnt = 0;
				}

				shark_move += cd; // 현재 이동거리를 넣어줌
				init(n); // 초기화
				cd = 0;
			}
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			// 범위 초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			// 재방문 및 물고기가 크다면
			if (visited[ny][nx] == 1 || board[ny][nx] > shark_size)
				continue;

			pq.push({ ny, nx, cd + 1 });
			visited[ny][nx] = 1;
		}
	}
	return shark_move;
}

int solution(int n, vector<vector<int>>& board) {
	int answer = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 9) {
				pq.push({ i,j,0 });
				board[i][j] = 0;
			}
		}
	}

	answer = BFS(n, board);
	return answer;
}

int main(void) {
	int n;
	vector<vector<int>> board;

	cin >> n;
	board.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			cin >> board[i][j];
	}

	int ret = solution(n, board);
	cout << ret;
	return 0;
}