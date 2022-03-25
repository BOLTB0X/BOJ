#include <iostream>
#include <vector>
#include <queue>
#define Max_Size 100001

using namespace std;

int BFS(int n, int k) {
	deque<int> dq;
	vector<int> visited(Max_Size, 0);

	dq.push_back(n);
	visited[n] = 1;

	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();

		if (cur == k)
			break;

		if (cur * 2 < Max_Size && visited[cur * 2] == 0) {
			visited[cur * 2] = visited[cur];
			dq.push_front(cur * 2);
		}

		if (cur - 1 >= 0 && visited[cur - 1] == 0) {
			visited[cur - 1] = visited[cur] + 1;
			dq.push_back(cur - 1);
		}
			
		if (cur + 1 < Max_Size && visited[cur + 1] == 0) {
			visited[cur + 1] = visited[cur] + 1;
			dq.push_back(cur + 1);
		}
	}

	return (visited[k] - 1);
}

int solution(int n, int k) {
	int answer = 0;

	answer = BFS(n, k);

	return answer;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	int ret = solution(n, k);
	cout << ret;

	return 0;
}
