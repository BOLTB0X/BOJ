#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char board[13][7];
bool visited[13][7];
vector<pair<int, int>> v; // ������ �ѵ� Ȯ��
vector<pair<int, int>> tmp; // ������ �ѵ� ����

// �����¿�
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// �Ϲ� DFS
void DFS(int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// ���� �ʰ�
		if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6)
			continue;

		// ��湮 �� �ٸ� �����̸�
		if (visited[ny][nx] == 1 || board[ny][nx] != board[y][x])
			continue;

		visited[ny][nx] = 1;
		tmp.push_back({ ny, nx });
		DFS(ny, nx);
	}
	return;
}

void board_update(void) {
	// ���� �͵� ����� ó��
	for (auto& p : v)
		board[p.first][p.second] = '.';

	for (int i = 10; i >= 0; --i) {
		for (int j = 0; j < 6; ++j) {
			// ����
			if (board[i][j] == '.')
				continue;

			int tmp_y = i;

			while (1) {
				// Ż�� ����
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
		v.clear(); // �ʱ�ȭ
		memset(visited, 0, sizeof(visited)); // �ʱ�ȭ

		// Ž��
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				// �ѿ�ѿ� �߰�
				if (board[i][j] != '.' && visited[i][j] == 0) {
					tmp.push_back({ i,j });
					visited[i][j] = 1;
					// ȣ��
					DFS(i, j);

					// ������ �ִٸ�
					if (tmp.size() >= 4) {
						flag = 1;
						for (auto& t : tmp)
							v.push_back(t);
					}
					tmp.clear(); //�ʱ�ȭ
				}
			}
		}

		//�� ������Ʈ
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