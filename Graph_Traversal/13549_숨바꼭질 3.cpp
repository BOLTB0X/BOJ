#include <iostream>
#include <vector>
#include <queue>
#define MLN 100001

using namespace std;

int solution(int n, int k) {
	int result = 0;
	deque<int> dq;
	vector<int> visited(MLN, 0);

	dq.push_back(n);
	visited[n] = 1;

	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();

		if (cur == k) 
			break;
		
		
		if (cur * 2 < MLN && visited[cur * 2] == 0) {
			visited[cur * 2] = visited[cur];
			dq.push_front(cur * 2);
		}

		if (cur + 1 < MLN && visited[cur + 1] == 0) {
			visited[cur + 1] = visited[cur] + 1;
			dq.push_back(cur + 1);
		}

		if (cur - 1 >= 0 && visited[cur - 1] == 0) {
			visited[cur - 1] = visited[cur] + 1;
			dq.push_back(cur - 1);
		}
		
	}
	result = visited[k] - 1;
	return result;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;

	cin >> n >> k;

	int ret = solution(n, k);
	cout << ret;
	return 0;
}
