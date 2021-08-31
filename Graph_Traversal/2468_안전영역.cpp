#include <iostream>
#include <cstring>
using namespace std;

int N;
int map[101][101];
bool visited[101][101];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int max(int a, int b) {
	return a > b ? a : b;
}

void DFS(int h, int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) 
			continue;
		if (visited[ny][nx] || map[ny][nx] <= h)
			continue;
		DFS(h, ny, nx);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int max_value = 1;
	int answer = 1;
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			max_value = max(max_value, map[y][x]);
		}
	}

	for (int h = 1; h < max_value; h++) {
		int result = 0;
		memset(visited, false, sizeof(visited));
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] > h && !visited[y][x]) {
					result++;
					DFS(h, y, x);
				}
			}
		}
		answer = max(answer, result);
	}
	cout << answer << '\n';
	return 0;
}