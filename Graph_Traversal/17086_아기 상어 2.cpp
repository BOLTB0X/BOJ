#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct POS {
	int y, x;
};

struct INF {
	int y, x, dist;
};

int n, m, result;
int sea[50][50];
bool visited[50][50];

vector<POS> block;


const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

//최대
int max(int a, int b) {
	return a > b ? a : b;
}

//방문초기화
void visit_init(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
	return;
}

int BFS(int y, int x) {
	queue<INF> q;
	q.push({ y,x,0 });
	visited[y][x] = true;

	while (!q.empty()) {
		INF cur = q.front();
		q.pop();

		if (sea[cur.y][cur.x] == 1)
			return cur.dist;

		for (int dir = 0; dir < 8; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
				if (!visited[ny][nx]) {
					visited[ny][nx] = true;
					q.push({ ny,nx,cur.dist + 1 });
				}
			}
		}
	}
}

//해결방안
void solution(void) {
	//각 상어 위치의 따른 거리 최댓값 구하기
	for (int i = 0; i < block.size(); i++) {
		//방문초기화
		visit_init();
		int y = block[i].y;
		int x = block[i].x;
		int safy_dist = BFS(y, x);
		result = max(result, safy_dist);
	}
	return;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			scanf("%d", &sea[y][x]);
			if (sea[y][x] == 0)
				block.push_back({ y,x });
		}
	}
	solution();
	printf("%d", result);
	return 0;
}