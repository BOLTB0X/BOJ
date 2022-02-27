#include <iostream>

using namespace std;

int result = -1;

//최대
int MAX(int a, int b) {
	return a > b ? a : b;
}

//깊이 우선 
void DFS(int* T, int* P, int n, int cur_day, int tot, int add_pay) {
	if (cur_day == n + 1) {
		result = MAX(result, tot);
		return;
	}
	else if (cur_day > n + 1) {
		result = MAX(result, tot - add_pay);
		return;
	}

	for (int i = cur_day; i <= n; i++) 
		DFS(T, P, n, i + T[i], tot + P[i], P[i]);
	return;
}

int solution(int n, int* T, int* P) {
	int answer = 0;
	
	//DFS로 완적탐색
	DFS(T, P, n, 1, 0, 0);
	answer = result;

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	//동적할당
	int* T = new int[(n + 1)];
	int* P = new int[(n + 1)];
	T[0] = P[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> T[i] >> P[i];

	int ret = solution(n, T, P);
	cout << ret; //출력

	//해제
	delete[] T;
	delete[] P;
	return 0;
}