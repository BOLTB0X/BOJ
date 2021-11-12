#include <iostream>

using namespace std;

void solution(void) {
	int n;
	cin >> n;

	long long result = 0;

	//  100이하 11의 배수들 
	// -> 11,22,33,44,55,66,77,88,99 총 9개 = 100/11
	for (int i = 1; i <= n; ++i)
		result += (n / i) * i;

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