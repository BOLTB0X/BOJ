#include <iostream>
#define MN 1001

using namespace std;

int cards[MN];
int dp[MN];

//최댓값 반환
int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer = 0;
	//dp테이블 초기화
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;
	
	
	//보텀업
	for (int i = 1; i <= n; ++i) {
		//i가 최대 카드를 갖는 개수, j가 카드 종류라 생각
		for (int j = 1; j <= i; ++j)
			dp[i] = MAX(dp[i - j] + cards[j], dp[i]);
	}

	answer = dp[n];

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> cards[i];
	
	int ret = solution(n);
	cout << ret;

	return 0;
}