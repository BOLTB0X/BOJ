#include <iostream>
#include <cstring>
#define Max_Size 100001
using namespace std;

typedef struct {
	int y, x;
} Pair;

Pair que[Max_Size];
int fr = 0, re = 0;

void enqueue(Pair data) {
	que[re++] = data;
	return;
}

void dequeue(void) {
	fr++;
	return;
}

int board[101][101];
int dist[101][101];

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int solution(int n, int m) {
	int answer = 0;
	// 방문리스트 초기화
	memset(dist, 0, 101);
	
	enqueue({ 0,0}); // 큐 삽입
	dist[0][0] = 1;

	while (fr < re) {
		int cy = que[fr].y;
		int cx = que[fr].x;
		dequeue(); // pop

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			// 범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// 재방문 또는 벽
			if (dist[ny][nx] != 0 || board[ny][nx] == 0)
				continue;
			
			dist[ny][nx] = dist[cy][cx] + 1;
			enqueue({ ny, nx });
		}
	}

	answer = dist[n - 1][m - 1];
	return answer;
}

int main(void) {
	int n, m;
	string tmp;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j) 
			board[i][j] = tmp[j] - '0';
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
