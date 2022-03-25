#include <iostream>
#include <vector>
#include <queue>
#define Max_Size 100001

using namespace std;

vector<int> solution(int n, int k) {
	vector<int> result; //결과
	queue<int> que; //큐
	vector<int> visited(Max_Size, 0); //방문리스트
	vector<int> path(Max_Size, 0); //기록

	que.push(n);
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
			break;
		}

		if (cur - 1 >= 0 && visited[cur - 1] == 0) {
			visited[cur - 1] = 1;
			path[cur - 1] = cur;
			que.push(cur - 1);
		}
		
		if (cur + 1 < Max_Size && visited[cur + 1] == 0) {
			visited[cur + 1] = 1;
			path[cur + 1] = cur;
			que.push(cur + 1);
		}
		
		if (cur * 2 < Max_Size && visited[cur * 2] == 0) {
			visited[cur * 2] = 1;
			path[cur * 2] = cur;
			que.push(cur * 2);
		}
	}

	return result;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> ret = solution(n, k);
	cout << ret.size() - 1 << '\n';
	
	for (int i = ret.size() - 1; i >= 0; --i)
		cout << ret[i] << ' ';

	return 0;
}
