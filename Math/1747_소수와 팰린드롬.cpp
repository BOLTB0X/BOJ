#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define Max_Size 1003002 // 1000000 이상 중 첫 소수

using namespace std;

vector<bool> prime(Max_Size, false);

void eratos(void) {
	prime[0] = prime[1] = 1;

	for (int i = 2; i * i < Max_Size; ++i) {
		if (prime[i])
			continue;

		for (int j = i + i; j < Max_Size; j += i)
			prime[j] = 1;
	}

	return;
}

int is_Panlindrome(int number) {
	string str = to_string(number); // 문지열 변환
	int size = str.length();
	
	for (int i = 0; i < size / 2; ++i) {
		if (str[i] != str[size - 1 - i])
			return 0;
	}

	return 1;
}

int solution(int n) {
	int answer = 0;

	eratos(); // 에라토스테네체

	for (int i = n; i < Max_Size; ++i) {
		if (prime[i])
			continue;

		if (is_Panlindrome(i)) {
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
