#include <iostream>

using namespace std;

int n, s;
int arr[20];
int cnt = 0;

void DFS(int idx, int tot) {
	if (idx == n)
		return;

	if (tot + arr[idx] == s)
		cnt++;

	DFS(idx + 1, tot);
	DFS(idx + 1, tot + arr[idx]);
}

void solution(void) {
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	//깊이우선탐색
	DFS(0, 0);
	cout << cnt << '\n';
	
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}