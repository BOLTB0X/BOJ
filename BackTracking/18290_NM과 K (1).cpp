#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> board;
vector<vector<bool>> visited;
int result = -0x7fffffff;

//��������
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

//�ִ񰪹�ȯ
int max(int a, int b) {
	return a > b ? a : b;
}

//���̿켱Ž��
void DFS(int depth, int tot) {
	//Ż������
	if (depth == k) {
		result = max(result, tot);
		return;
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			//��湮�� ���
			if (visited[y][x])
				continue;

			//üũ��
			bool flag = true;

			//�������� ����
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				//�����ʰ�
				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (visited[ny][nx])
					flag = false;
			}

			//������ �����ϴٸ�
			if (flag) {
				visited[y][x] = true;
				DFS(depth + 1, tot + board[y][x]);
				visited[y][x] = false;
			}
		}
	}
	return;
}

void solution(void) {
	cin >> n >> m >> k;

	//�ʰ� �湮����Ʈ �ʱ�ȭ
	board.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m, false));

	//�Է�
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x)
			cin >> board[y][x];
	}

	//��Ʈ��ŷ ����
	DFS(0, 0);

	//���
	cout << result << '\n';
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}