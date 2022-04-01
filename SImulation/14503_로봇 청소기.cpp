#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int y, x, dir;
} Robot;

int board[50][50];

// 0 �� 1 �� 2 �� 3 ��
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

// �������� ȸ��
int turn_left(int d) {
	if (d == 0)
		return 3;
	return d - 1;
}

// ����
int turn_back(int d) {
	if (d == 0)
		return 2;

	else if (d == 1)
		return 3;

	else if (d == 2)
		return 0;

	else if (d == 3)
		return 1;
}

int solution(int n, int m, int sy, int sx, int sd) {
	int answer = 1;
	int flag = 0;

	queue<Robot> que; // ť
	board[sy][sx] = 2; // û��ó��
	que.push({ sy,sx,sd });

	while (!que.empty()) {
		// Ż�� ����
		if (flag == 1)
			break;

		int cy = que.front().y;
		int cx = que.front().x;
		int cd = que.front().dir;
		int tmp = cd;
		que.pop();

		// ���� ���� �������� ���ʺ��� ���ʷ�
		for (int i = 0; i < 4; ++i) {
			tmp = turn_left(tmp);
			int ny = cy + dy[tmp];
			int nx = cx + dx[tmp];

			// �����ʰ�
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// 2 - a ����
			if (board[ny][nx] == 0) {
				board[ny][nx] = 2;
				answer++;
				que.push({ ny, nx, tmp });
				break;
			}

			// ������ �� ���
			else if (i == 3) {
				// ���� ����
				int ny = cy + dy[turn_back(cd)];
				int nx = cx + dx[turn_back(cd)];

				// �����ʰ�
				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;

				// 2 - d ����
				if (board[ny][nx] == 1) {
					flag = 1;
					break;
				}
				que.push({ ny, nx, cd }); // �ٶ󺸴� ������ ������ ä
			}
		}
	}

	return answer;
}

int main(void) {
	int n, m;
	int sy, sx, sd;
	
	cin >> n >> m;
	cin >> sy >> sx >> sd;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, m, sy, sx, sd);
	cout << ret;
	return 0;
}