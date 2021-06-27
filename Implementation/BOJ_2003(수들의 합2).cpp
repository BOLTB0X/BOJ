#include <iostream>
using namespace std;
int arr[10001] = {0};
int n, m;

int solution() {
	cin >> n >> m;
	int start= 0, end = 0; // 시작 , 끝
	int partial_sum = 0, cnt = 0; //합과 횟수
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	while (end<=n) { //end가 배열의 길이를 따라잡기 전까지
		if (partial_sum >= m)
			partial_sum -= arr[start++]; //부분 합이 타겟m보다 크면 arr에 처음부터 빼준다.
		else if (partial_sum < m)
			partial_sum += arr[end++]; //부분 합이 타겟m보다 작으면면 arr에 end를 증가시키며 더해준다.
		if (partial_sum == m) cnt++; //부분 합이 타겟 m에 도달하면 cnt 1증가
	}
	return cnt; //총 횟수를 반환
}

int main() {
	cout << solution() << '\n';
	return 0;
}