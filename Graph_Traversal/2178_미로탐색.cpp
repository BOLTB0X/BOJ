#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
int board[101][101];
bool visited[101][101] = { false, };

//�����¿�
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//�Է�
void input(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; ++j) {
			board[i][j] = (tmp[j] - '0');
		}
	}
}

//�ʺ�켱Ž��
void BFS(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({ y,x });
	
	//ť�� ��������
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		//�����¿� Ž��
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			//�����ʰ�
			if (ny >= n || nx >= m || nx < 0 || ny < 0)
				continue;
			//��湮 �Ǵ� ���� ���
			if (visited[ny][nx] || board[ny][nx] == 0)
				continue;
			//�Ÿ� üũ
			board[ny][nx] = board[cy][cx] + 1;
			visited[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

//�ùķ��̼�
void simulation(void) {
	//�Է�
	input();
	//BFS����
	BFS(0, 0);
	//�ּҰŸ��� �������� ���� ������ ��ġ
	cout << board[n - 1][m - 1] << '\n';
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//�ùĽ���
	simulation();
	return 0;
}