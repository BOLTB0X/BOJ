#include <iostream>

using namespace std;

int result;

//깊이 우선 탐색
void DFS(int n, int tot) {
	//탈출조건 == 넘길시
	if (tot > n)
		return;
	//된다면
	if (tot == n)
		result++;
	for (int i = 1; i <= 3; ++i)
		DFS(n, tot + i);
	return;
}

void solution(void) {
	int T;
	cin >> T;

	while (T--) {
		//입력
		int n;
		cin >> n;

		//DFS전 초기화 
		result = 0;
		//DFS 호출
		DFS(n, 0);

		//출력
		cout << result << '\n';
	}
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