#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int cnt = 0; //각 총단지 수
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
string graph[26];
vector<int> answer; //아파트 단지별 카운트용 벡터
bool visited[26][26];

void bfs(int x, int y) {
	queue< pair<int, int> > que;
	que.push(make_pair(x, y));
	visited[x][y] = true;
	while (!que.empty()) {
		cnt += 1;
		int a = que.front().first;
		int b = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) { //범위 내에 있고
				if (graph[nx][ny] == '1' && visited[nx][ny] == false) { //아직 방문하지 않은 집
					que.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> graph[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == '1' && visited[i][j] == false)
			{
				cnt = 0;
				bfs(i, j);
				answer.push_back(cnt);
			}
		}
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
	return 0;
}