#include <iostream>
#include <vector>
#include <queue>
#define Max_Size 100001

using namespace std;

int solution(int n, int k) {
	int answer = 0;
	vector<int> visited(Max_Size, 0); // 방문리스트
	queue<int> que;
	
	que.push(n);
	visited[n] = 1;

	// BFS
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == k) {
			answer = visited[cur] - 1;
			break;
		}

		else {
			if (cur + 1 < Max_Size && visited[cur + 1] == 0) {
				visited[cur + 1] = visited[cur] + 1;
				que.push(cur + 1);
			}
			
			if (cur - 1 >= 0 && visited[cur - 1] == 0) {
				visited[cur - 1] = visited[cur] + 1;
				que.push(cur - 1);
			}
			
			if (cur * 2 < Max_Size && visited[cur * 2] == 0) {
				visited[cur * 2] = visited[cur] + 1;
				que.push(cur * 2);
			}
		}
	}

	return answer;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	int ret = solution(n, k);
	cout << ret;
	return 0;
}
