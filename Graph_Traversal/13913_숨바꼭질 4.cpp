#include <iostream>
#include <vector>
#include <queue>
#define MLN 100001

using namespace std;

vector<int> solution(int n, int k) {
	vector<int> result; //���
	queue<int> que; //ť
	vector<int> visited(MLN, 0); //�湮����Ʈ
	vector<int> path(MLN, 0); //��� ����

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

		if (cur + 1 < MLN && visited[cur + 1] == 0) {
			que.push(cur + 1);
			visited[cur + 1] = 1;
			path[cur + 1] = cur;
		}
		
		if (cur - 1 >= 0 && visited[cur - 1] == 0) {
			que.push(cur - 1);
			visited[cur - 1] = 1;
			path[cur - 1] = cur;
		}
		
		if (cur * 2 < MLN && visited[cur * 2] == 0) {
			que.push(cur * 2);
			visited[cur * 2] = 1;
			path[cur * 2] = cur;
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