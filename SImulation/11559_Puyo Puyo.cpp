#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char board[13][7];
bool visited[13][7];
vector<pair<int, int>> v; // 터지는 넘들 확인
vector<pair<int, int>> tmp; // 터지는 넘들 예비

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// 일반 DFS
void DFS(int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 범위 초과
		if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6)
			continue;

		// 재방문 및 다른 종류이면
		if (visited[ny][nx] == 1 || board[ny][nx] != board[y][x])
			continue;

		visited[ny][nx] = 1;
		tmp.push_back({ ny, nx });
		DFS(ny, nx);
	}
	return;
}

void board_update(void) {
	// 터진 것들 빈공간 처리
	for (auto& p : v)
		board[p.first][p.second] = '.';

	for (int i = 10; i >= 0; --i) {
		for (int j = 0; j < 6; ++j) {
			// 여백
			if (board[i][j] == '.')
				continue;

			int tmp_y = i;

			while (1) {
				// 탈출 조건
				if (tmp_y == 11 || board[tmp_y + 1][j] != '.')
					break;
				board[tmp_y + 1][j] = board[tmp_y][j];
				board[tmp_y][j] = '.';
				tmp_y++;
			}
		}
	}

	return;
}

int solution(void) {
	int flag;
	int answer = 0;

	while (1) {
		flag = 0;
		v.clear(); // 초기화
		memset(visited, 0, sizeof(visited)); // 초기화

		// 탐색
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				// 뿌요뿌요 발견
				if (board[i][j] != '.' && visited[i][j] == 0) {
					tmp.push_back({ i,j });
					visited[i][j] = 1;
					// 호출
					DFS(i, j);

					// 터질수 있다면
					if (tmp.size() >= 4) {
						flag = 1;
						for (auto& t : tmp)
							v.push_back(t);
					}
					tmp.clear(); //초기화
				}
			}
		}

		//맵 업데에트
		board_update();
		if (flag == 1)
			answer++;
		else 
			break;
	}

	return answer;
}

int main(void) {
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j)
			cin >> board[i][j];
	}

	int ret = solution();
	cout << ret;

	return 0;
}