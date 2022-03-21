#include <iostream>
#include <string>
#include <cstring>
#define ML 1003002

using namespace std;

int prime[ML];

void eratos(void) {
	prime[0] = prime[1] = 1;

	for (int i = 2; i * i < ML; ++i) {
		if (prime[i] == 1)
			continue;

		for (int j = i + i; j < ML; j += i) 
			prime[j] = 1;
	}
	return;
}

int check(int number) {
	string n = to_string(number);

	for (int i = 0; i < n.length() / 2; ++i) {
		if (n[i] != n[n.length() - 1 - i])
			return 0;
	}
	
	return 1;
}

int solution(int n) {
	int answer = 0;
	memset(prime, 0, ML); // 배열 초기화

	eratos();

	for (int i = n; i < ML; ++i) {
		if (prime[i] == 1)
			continue;

		//체크
		if (check(i) == 1) {
			answer = i;
			break;
		}
	}

	return answer;
}

int main(void) {
	int n;
	cin >> n;

	int ret = solution(n);
	cout << ret;

	return 0;
}