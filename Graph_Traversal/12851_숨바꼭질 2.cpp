#include <iostream>
#include <vector>
#include <queue>
#define Max_Size 100001

using namespace std;

int result, cnt;

// 너비우선 탐색
void BFS(int n, int k) {
	vector<int> visited(Max_Size, 0); // 방문리스트
	queue<pair<int, int>> que;
	que.push({ n, 0 });
	visited[n] = 1;

	while (!que.empty()) {
		int cur = que.front().first;
		int path = que.front().second;
		visited[cur] = 1; // pop할때 방문 체크
		que.pop();

		// 답이 나왔고 도달했다면
		if (result && result == path && cur == k) 
			cnt++;
		
		if (!result && cur == k) {
			result = path;
			cnt++;
		}

		else {
			if (cur + 1 < Max_Size && visited[cur + 1] == 0)
				que.push({ cur + 1, path + 1 });
			
			if (cur - 1 >= 0 && visited[cur - 1] == 0)
				que.push({ cur - 1, path + 1 });
			
			if (cur * 2 < Max_Size && visited[cur * 2] == 0)
				que.push({ cur * 2, path + 1 });
		}
	}
	return;
}

vector<int> solution(int n, int k) {
	vector<int> answer;
	result = 0, cnt = 0;

	BFS(n, k); // 너비우선 탐색

	answer.push_back(result);
	answer.push_back(cnt);
	return answer;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	vector<int> ret = solution(n, k);
	cout << ret[0] << '\n' << ret[1];
	return 0;
}
