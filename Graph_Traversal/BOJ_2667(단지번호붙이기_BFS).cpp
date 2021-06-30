#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue> //bfs를 사용하기 때문
using namespace std;

int n;
int cnt; //단지내의 아파트 갯수
string graph[26];
queue< pair<int, int> > que;
vector<int> answer;
bool visited[26][26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int x, int y) {
	que.push(make_pair(x, y));
	visited[x][y] = true;
	while (!que.empty()) {
		int temp_x = que.front().first;
		int temp_y = que.front().second;
		que.pop();
		cnt++; //pop마다 단지내 아파트 수 카운트
		for (int i = 0; i < 4; i++) {
			int nx = temp_x + dx[i];
			int ny = temp_y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (graph[nx][ny] == '1' && visited[nx][ny] == false) {
					que.push(make_pair(nx, ny));
					visited[nx][ny] = true; //방문처리
				}
			}
		}
	}
}

void solution(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> graph[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == '1' && !visited[i][j]) {
				cnt = 0; //단지 스타트
				bfs(i, j);
				answer.push_back(cnt);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}

int main(void) {
	solution();
	return 0;
}
