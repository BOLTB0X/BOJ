#include <iostream>
#include <vector>

using namespace std;

int n, result = -0x7fffffff;
vector<int> days;
vector<int> pay;

//최댓값반환
int max(int a, int b) {
	return a > b ? a : b;
}

void DFS(int cur_day, int add_pay, int tot) {
	//탈출 조건
	if (cur_day == n + 1) {
		result = max(result, tot);
		return;
	}
	
	//만약 엄청 넘어 선다면
	else if (cur_day > n + 1) {
		result = max(result, tot - add_pay);
		return;
	}

	//각 날로 DFS호출
	for (int i = cur_day; i <= n; ++i)
		DFS(i + days[i], pay[i], tot + pay[i]);
}

void solution(void) {
	cin >> n;

	//벡터 사이즈 설정
	days.resize(n + 1, 0);
	pay.resize(n + 1, 0);

	for (int i = 1; i <= n; ++i) 
		cin >> days[i] >> pay[i];
	
	//깊이우선탐색
	DFS(1, 0, 0);

	//출력
	cout << result << '\n';
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