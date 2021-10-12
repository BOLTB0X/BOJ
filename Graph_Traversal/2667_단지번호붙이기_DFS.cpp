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

//상하좌우
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

//입력
void input(void) {
	scanf("%d", &N);
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%1d", &board[y][x]);
		}
	}
	return;
}

//깊이 우선
void DFS(int y, int x) {
	visited[y][x] = true;
	apart_size++;

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		//범위 초과
		if (ny >= N || nx >= N || ny < 0 || nx < 0)
			continue;
		//재방문 또는 0인 경우
		if (visited[ny][nx] || board[ny][nx] == 0)
			continue;
		//호출
		DFS(ny, nx);
	}
	return;
}

//문제해결
void solution(void) {
	//입력
	input();
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			//아파트를 발견하고 미 방문인 경우
			if (board[y][x] == 1 && !visited[y][x]) {
				apart_size = 0;
				DFS(y, x);
				answer.push_back(apart_size);
			}
		}
	}
	//오름차순 정렬
	sort(answer.begin(), answer.end());
	//정답 출력
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << '\n';
	}
	cout << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//해결
	solution();
	return 0;
}