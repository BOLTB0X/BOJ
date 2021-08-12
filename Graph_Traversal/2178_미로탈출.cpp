#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
bool visited[101][101];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0, -1 };

void BFS(int y, int x) {
	queue<pair<int, int>> que;
	que.push({y,x});
	visited[y][x] = true;

	while (!que.empty()) {
		int cur_y = que.front().first;
		int cur_x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (0 <= next_y && next_y < n && 0 <= next_x && next_x < m) {
				if (map[next_y][next_x] == 1 && !visited[next_y][next_x]) {
					map[next_y][next_x] = map[cur_y][cur_x] + 1;
					que.push({ next_y,next_x });
					visited[next_y][next_x];
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	BFS(0,0);
	printf("%d", map[n-1][m-1]);
	return 0;
}