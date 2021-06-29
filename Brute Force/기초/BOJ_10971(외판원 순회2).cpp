#include <iostream>
#include <algorithm>
#define INF 99999999;
using namespace std;

int n;
int graph[11][11];
int visited[11];
int answer = INF;
int temp = 0; //임시 순회비용 저장 공간


int check()
{
	for (int i = 1; i < n; i++)
	{
		if (visited[i] == 0)
		{
			return 0;
		}
	}
	return 1;
}

void dfs(int sum, int cur) {
	if (check() == 1) //모두 방문한 경우
	{
		if (graph[cur][0] != 0) {
			sum += graph[cur][0];
			if (sum < answer)
				answer = sum;
		}
	}
	for (int i = 1; i < n; i++) {
		if (graph[cur][i] != 0 && visited[i] == 0) {
			visited[i] = 1;
			dfs(sum + graph[cur][i], i);
			visited[i] = 0;
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0, 0);
	cout << answer;
}