#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int y, x, dir;
} Block;

Block que[25003];
int fr = 0, re = 0;

void enqueue(Block data) {
	que[re++] = data;
	return;
}

Block dequeue(void) {
	return que[fr++];
}

int board[51][51];
//�� �� �� ��
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

//�������� ƴ
int turn_left(int dir) {
	if (dir == 0)
		return 3;
	else if (dir == 1)
		return 0;
	else if (dir == 2)
		return 1;
	else if (dir == 3)
		return 2;
}

//����
int turn_back(int dir) {
	if (dir == 0)
		return 2;
	else if (dir == 1)
		return 3;
	else if (dir == 2)
		return 0;
	else if (dir == 3)
		return 1;
}

int solution(int n, int m) {
	int flag = 0;
	int answer = 1;

	//BFS ����
	while (fr < re) {
		//���� ���� ���
		if (flag == 1)
			break;

		Block cur = dequeue();
		int td = cur.dir;

		for (int dir = 0; dir < 4; ++dir) {
			//���� ������� ���ʷ�
			td = turn_left(td);
			int ny = cur.y + dy[td];
			int nx = cur.x + dx[td];

			//�����ʰ�
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			//û�Ҹ� �ؾ��ϴ� ���
			if (board[ny][nx] == 0) {
				board[ny][nx] = 2;
				Block next = { ny, nx, td };
				enqueue(next);
				answer++; //ī��Ʈ
				//�ٽ� 1������ ���ư����ϹǷ�
				break;
			}

			//������ �� ���
			else if (dir == 3) {
				//������ ���� ���h��ȯ
				td = turn_back(cur.dir);
				int ny = cur.y + dy[td];
				int nx = cur.x + dx[td];

				//�����ʰ�
				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;

				//�����ߴµ� ���� ��� ���� ��ž
				if (board[ny][nx] == 1) {
					flag = 1;
					break;
				}
	
				//���� �� ������ �ִٸ�
				//�ٶ󺸴� ������ ������ ä
				Block next = { ny, nx, cur.dir };
				enqueue(next);
			}
		}
	}
	return answer;
}

int main(void) {
	int n, m, sy, sx, sd;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &sy, &sx, &sd);
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);
	}
	
	Block robot = { sy, sx, sd };
	enqueue(robot);

	board[sy][sx] = 2; //û�� ó��
	int ret = solution(n, m);

	printf("%d", ret);
	return 0;
}