#include <iostream>
#include <vector>

using namespace std;

int result = -1;
int board[9][9];
int tmp[9][9]; //�����

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

//�ִ� ��ȯ
int Max(int a, int b) {
	return a > b ? a : b;
}

//���
void backup(int n, int m) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			tmp[i][j] = board[i][j];
	}

	return;
}

void DFS(int n, int m, int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		//�����ʰ�
		if (ny < 1 || nx < 1 || ny > n || nx > m)
			continue;
		
		//���̰ų� ���̷���
		if (tmp[ny][nx] == 1 || tmp[ny][nx] == 2)
			continue;

		tmp[ny][nx] = 2;
		DFS(n, m, ny, nx);
	}

	return;
}

//�ִ� ��������
int get_Safe_size(int n, int m) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (tmp[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

void make_wall(int n, int m, int cnt) {
	if (cnt == 3) {
		//���
		backup(n, m);

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (tmp[i][j] == 2)
					DFS(n, m, i, j);
			}
		}
	
		result = Max(result, get_Safe_size(n, m));
		return;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			//���� �߰� -> ��Ʈ��ŷ
			if (board[i][j] == 0) {
				cnt++;
				board[i][j] = 1;
				make_wall(n, m, cnt);
				board[i][j] = 0;
				cnt--;
			}
		}
	}

	return;

}

int solution(int n, int m) {
	int answer = 0;

	make_wall(n, m, 0);
	answer = result;
	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, m);
	cout << ret;

	return 0;
}