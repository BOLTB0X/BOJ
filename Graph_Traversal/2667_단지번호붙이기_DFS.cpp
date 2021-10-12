#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[26][26];
bool visited[26][26] = { false, };

int apart_size;
vector<int> answer;

//�����¿�
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

//�Է�
void input(void) {
	scanf("%d", &N);
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%1d", &board[y][x]);
		}
	}
	return;
}

//���� �켱
void DFS(int y, int x) {
	visited[y][x] = true;
	apart_size++;

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		//���� �ʰ�
		if (ny >= N || nx >= N || ny < 0 || nx < 0)
			continue;
		//��湮 �Ǵ� 0�� ���
		if (visited[ny][nx] || board[ny][nx] == 0)
			continue;
		//ȣ��
		DFS(ny, nx);
	}
	return;
}

//�����ذ�
void solution(void) {
	//�Է�
	input();
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			//����Ʈ�� �߰��ϰ� �� �湮�� ���
			if (board[y][x] == 1 && !visited[y][x]) {
				apart_size = 0;
				DFS(y, x);
				answer.push_back(apart_size);
			}
		}
	}
	//�������� ����
	sort(answer.begin(), answer.end());
	//���� ���
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << '\n';
	}
	cout << '\n';
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//�ذ�
	solution();
	return 0;
}