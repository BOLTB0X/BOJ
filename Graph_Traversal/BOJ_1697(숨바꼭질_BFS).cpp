#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int n, k; //n은 수빈이 위치 , k는 동생위치== 타겟
int t[MAX] = { 0, };
queue<int> que;

int BFS(int n,int k) {
	que.push(n); //
	t[n] = 1; //방문처리
	while (!que.empty()) {
		int x = que.front();
		que.pop();

		if (x == k) return (t[x] - 1); //동생위치에 간다면

		if (x + 1 < MAX && x + 1 >= 0 && t[x + 1] == 0) { //범위에 해당하고 미 방문이면
			que.push(x + 1);
			t[x + 1] = t[x] + 1;
		}

		if (x - 1 < MAX && x - 1 >= 0 && t[x - 1] == 0) { //범위에 해당하고 미 방문이면
			que.push(x - 1);
			t[x - 1] = t[x] + 1;
		}

		if (x * 2 < MAX && x * 2 >= 0 && t[x * 2] == 0) { //범위에 해당하고 미 방문이면
			que.push(x * 2);
			t[x * 2] = t[x] + 1;
		}
	}
}

int main(void) {
	cin >> n >> k;
	
	int answer = BFS(n, k);

	cout << answer << '\n';
	return 0;
}
