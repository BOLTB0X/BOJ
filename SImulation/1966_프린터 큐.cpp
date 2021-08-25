#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

int solution(int arr[], int len, int target) {
	queue<pair<int, int>> q;
	priority_queue<int> pq;

	for (int i = 0; i < len; i++) {
		q.push({ i,arr[i] });
		pq.push(arr[i]);
	}

	int order = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();

		if (cur.second >= pq.top()) {
			if (cur.first == target) {
				return order;
			}
			pq.pop();
			q.pop();
			order++;
		}
		else {
			q.push(cur);
			q.pop();
		}
	}
}

int main(void) {
	int T;

	scanf("%d", &T);
	while (T>0) {
		int n, m;
		int arr[100];

		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		int ret = solution(arr,n,m);
		printf("%d\n", ret);
		T -= 1;
	}
	return 0;
}