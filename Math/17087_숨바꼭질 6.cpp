#include <iostream>

using namespace std;

//유클리드 호제법
int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

void solution(void) {
	int N, S;
	int gcd_value = -1;
	cin >> N >> S;

	//각 거리차의 약수 중 최대가 되는 수
	while (N--) {
		int a;
		cin >> a;

		int dist = (S > a) ? (S - a) : (a - S);
		if (gcd_value != -1)
			gcd_value = gcd(gcd_value, dist);

		else
			gcd_value = dist;
	}

	cout << gcd_value << '\n';
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