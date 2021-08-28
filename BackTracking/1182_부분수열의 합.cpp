#include <iostream>
using namespace std;

int N, S;
int arr[20];
int cnt = 0;

void DFS(int idx, int tot) {
	if (idx == N) 
		return;
	
	if (tot + arr[idx] == S)
		cnt++;

	DFS(idx + 1, tot);
	DFS(idx + 1, tot + arr[idx]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	DFS(0,0);
	cout << cnt << '\n';
	return 0;
}