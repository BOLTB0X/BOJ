#include<iostream>
#include<queue>
using namespace std;
#define MAX 100001

int n, k;
int cnt[MAX] = {0,};

int bfs() {
	queue<int> que;
	que.push(n);
	cnt[n] = 1;
	while (!que.empty()) {
		int step = que.front();
		que.pop();

		if (step == k) {
			return cnt[step]-1;
		}
		if (step + 1 < MAX && cnt[step + 1] == 0) {
			que.push(step + 1);
			cnt[step + 1] = cnt[step] + 1;
		}
		if (step - 1 < MAX && cnt[step - 1]==0) {
			que.push(step - 1);
			cnt[step - 1] = cnt[step] + 1;
		}
		if (step * 2 < MAX && cnt[step * 2] == 0) {
			que.push(step * 2);
			cnt[step * 2] = cnt[step] + 1;
		}
	}
}

int main() {
	cin >> n >> k;
	int answer = bfs();
	cout << answer;
}