#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int solution(int n, int m, vector<int>& printer) {
	int answer = 1;
	queue<pair<int,int>> que;
	priority_queue<int> pq;

	for (int i = 0; i < printer.size(); ++i) {
		que.push({ i, printer[i] });
		pq.push(printer[i]);
	}

	while (!que.empty()) {
		int cur = que.front().first;
		int value = que.front().second;
		que.pop();

		if (value >= pq.top()) {
			// 원하는 번호가 출력될 때
			if (cur == m)
				break;
			pq.pop();
			answer++; // pq가 pop할 때마다
		}

		else 
			que.push({ cur,value });
	}

	return answer;
}

int main(void) {
	int T;

	cin >> T;
	while (T--) {
		int n, m;
		vector<int> printer;

		cin >> n >> m;
		printer = vector<int>(n);
		for (int i = 0; i < n; ++i)
			cin >> printer[i];

		int ret = solution(n, m, printer);
		cout << ret << '\n';
	}

	return 0;
}
