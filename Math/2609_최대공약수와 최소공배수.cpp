#include <iostream>

using namespace std;

//최대공약수
int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

//최소공배수
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

void solution(void) {
	int a, b;

	cin >> a >> b;
	
	//최대공약수, 최소공배수 
	int ret1 = gcd(a, b);
	int ret2 = lcm(a, b);

	cout << ret1 << '\n';
	cout << ret2 << '\n';

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