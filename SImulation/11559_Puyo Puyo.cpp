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

// 깊이우선탐색
void DFS(int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6)
			continue;

		if (visited[ny][nx] == 1)
			continue;

		if (board[ny][nx] != board[y][x])
			continue;

		tmp.push_back({ ny, nx });
		visited[ny][nx] = 1;
		DFS(ny, nx);
	}
	return;
}

void board_update(void) {
	// 빈공간으로 수정
	for (auto& pos : v)
		board[pos.first][pos.second] = '.';

	// row 거꾸로
	for (int i = 10; i >= 0; --i) {
		// col은 그대로
		for (int j = 0; j < 6; ++j) {
			// 여백
			if (board[i][j] == '.')
				continue;

			// 블록 발견
			int tmp_y = i;

			// 아래로 떨어짐
			while (1) {
				// 바닥 또는 빈 공간이 아니라면
				if (tmp_y == 11 || board[tmp_y + 1][j] != '.')
					break;

				board[tmp_y + 1][j] = board[tmp_y][j];
				board[tmp_y][j] = '.';
				tmp_y++; // 떨어짐
			}
		}
	}
	return;
}

int solution(void) {
	int flag;
	int answer = 0;
	
	// 시뮬레이션 시작
	while (1) {
		flag = 0;
		v.clear(); // 터치는 블록들 초기화
		memset(visited, 0, sizeof(visited)); // 방문리스트 초기화

		// 블록 탐색 시작
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (board[i][j] != '.' && visited[i][j] == 0) {
					tmp.push_back({ i,j }); // 예비 삽입

					visited[i][j] = 1;
					DFS(i, j);
					
					// 터질수 있다면?
					if (tmp.size() >= 4) {
						flag = 1;
						for (auto& t : tmp)
							v.push_back(t);
					}
					tmp.clear(); // 초기화
				}
			}
		}
		
		// 맵 업데이트
		board_update();
		if (flag == 1)
			answer++;
		else
			break;
	}
	
	return answer;
}

int main(void) {
	// 맵 입력
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j)
			cin >> board[i][j];
	}

	int ret = solution();
	cout << ret;

	return 0;
}
