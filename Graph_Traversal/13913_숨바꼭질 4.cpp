#include <iostream>
#include <queue>
#include <vector>
#define Max_Size 100001 // 최대길이

using namespace std;

vector<int> BFS(int n, int k) {
	vector<int> visited(Max_Size, 0); // 방문리스트
	vector<int> result;
	vector<int> path(Max_Size, 0);
	queue<int> que;

	que.push(n);
	path.push_back(n);
	visited[n] = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == k) {
			int idx = cur;

			while (idx != n) {
				result.push_back(idx);
				idx = path[idx];
			}
			result.push_back(n);

			return result;
		}
		
		else {
			if (cur * 2 < Max_Size && visited[cur * 2] == 0) {
				visited[cur * 2] = 1;
				path[cur * 2] = cur;
				que.push(cur * 2);
			}

			if (cur + 1 < Max_Size && visited[cur + 1] == 0) {
				visited[cur + 1] = 1;
				path[cur + 1] = cur;
				que.push(cur + 1);
			}
			
			if (cur - 1 >= 0 && visited[cur - 1] == 0) {
				visited[cur -1] = cur;
				path[cur - 1] = cur;
				que.push(cur - 1);
			}
		}
	}
}

vector<int> solution(int n, int k) {
	vector<int> answer = BFS(n, k);
	return answer;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	vector<int> ret = solution(n, k);

	// 출력
	cout << ret.size() - 1 << '\n';
	for (int i = ret.size() - 1; i >= 0; --i)
		cout << ret[i] << ' ';

	return 0;
}
