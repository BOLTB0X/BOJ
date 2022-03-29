#include <iostream>

using namespace std;

long solution(int a, int b){
	long long answer = 0;
	string seq = "";
	
	// 수열 생성
	for (int i = 1; i <= b; ++i) {
		for (int j = 1; j <= i; ++j)
			seq.push_back(i + '0');
	}

	for (int i = a - 1; i < b; ++i)
		answer += (seq[i] - '0');

	return answer;
}

int main(void) {
	int a, b;

	cin >> a >> b;
	long long ret = solution(a, b);
	cout << ret;
	return 0;
}
