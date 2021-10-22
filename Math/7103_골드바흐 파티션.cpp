#include <iostream>
#include <cmath>

using namespace std;

//최대값 셋팅
#define MAX 1000000

//숫자배열 셋팅
int numbers[MAX] = { 0, };

//셋팅
void init(void) {
	//골드바흐 
	numbers[0] = numbers[1] = 1;
	for (int i = 2; i <= (int)sqrt(MAX); ++i) {
		for (int j = i * i; j <= MAX; j += i) {
			//1이면 소수가 아님
			if (numbers[j] % i == 0)
				numbers[j] = 1;
		}
	}
	return;
}

void solution(void) {
	//골드바흐 추측을 위한 셋팅
	init();

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int cnt = 0;
		//파티션 구하기
		for (int i = n / 2; i > 0; i--) {
			//발견 카운트
			if (numbers[i] != 1 && numbers[n - i] != 1) {
				cnt++;
			}
		}
		cout << cnt << '\n';
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