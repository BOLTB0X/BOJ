#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K, area;
int board[100][100] = { 0, };
bool visited[100][100] = { false, };

vector<int> answer;

//�����¿�
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,-1,1 };

//�����ǿ� �ش� ��ǥ���� ǥ��
void marking_board(int x1, int y1, int x2, int y2) {
	for (int y = y1; y < y2; ++y) {
		for (int x = x1; x < x2; ++x) {
			board[y][x] = 1;
			visited[y][x] = true;
		}
	}
	return;
}

//�Է�
void input(void) {
	cin >> M >> N >> K;
	while (K--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		marking_board(x1, y1, x2, y2);
	}
}

//���� �켱
void DFS(int x, int y) {
	visited[x][y] = true;
	area++;

	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		//���� �ʰ�
		if (nx >= M || ny >= N || ny < 0 || nx < 0)
			continue;
		//��ĥ �Ȱ��� ���
		if (board[nx][ny] == 1 || visited[nx][ny])
			continue;
		DFS(nx, ny);
	}
	return;
}

//�ذ�
void solution(void) {
	//�Է�
	input();

	for (int x = 0; x < M; ++x) {
		for (int y = 0; y < N; ++y) {
			//������ �߰��ϸ�
			if (board[x][y] == 0 && !visited[x][y]) {
				area = 0;
				DFS(x, y);
				answer.push_back(area);
			}
		}
	}
	cout << answer.size() << '\n';
	//�������� ����
	sort(answer.begin(), answer.end());
	//���
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
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