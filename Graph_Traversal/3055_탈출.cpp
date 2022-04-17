#include <iostream>
#include <string>
#include <vector>
#define INF 1e9

using namespace std;

typedef struct {
	int y, x, dist;
} Node;

Node que[2511];
int fr, re;

char board[50][50];
vector<vector<int>> visited;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

void push(int y, int x, int dist) {
	if (visited[y][x] <= dist)
		return;

	visited[y][x] = dist;
	que[re++] = { y,x,dist };
	return;
}

void BFS(int r, int c) {
	while (fr < re) {
		int cy = que[fr].y;
		int cx = que[fr].x;
		int cd = que[fr].dist;
		fr++;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			int nd = cd + 1;

			// �����ʰ�
			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;

			push(ny, nx, nd);
		}
	}
	return;
}

int solution(int r, int c) {
	int answer = -1;
	int sy, sx, ey, ex;
	visited = vector<vector<int>>(r, vector<int>(c, INF));
	fr = 0, re = 0; // ť �ʱ�ȭ

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			// �����
			if (board[i][j] == 'D')
				ey = i, ex = j;

			// ��
			else if (board[i][j] == 'X')
				visited[i][j] = 0;

			// ������
			else if (board[i][j] == 'S')
				sy = i, sx = j;

			// ��
			else if (board[i][j] == '*')
				push(i, j, 0);

		}
	}

	// ���� ���� ����⵵�� 
	visited[ey][ex] = 0;
	BFS(r, c);

	// �ٽ� ��� ��������
	fr = 0, re = 0;
	visited[ey][ex] = INF;
	push(sy, sx, 0);
	BFS(r, c);

	if (visited[ey][ex] < INF)
		answer = visited[ey][ex];
	return answer;
}

int main(void) {
	int r, c;
	string tmp;

	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		cin >> tmp;
		for (int j = 0; j < c; ++j) 
			board[i][j] = tmp[j];
	}

	int ret = solution(r, c);
	if (ret == -1)
		cout << "KAKTUS";
	else
		cout << ret;
	return 0;
}