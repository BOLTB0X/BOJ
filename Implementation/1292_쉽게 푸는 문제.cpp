#include <iostream>

using namespace std;

long solution(int a, int b){
	long long answer = 0;
	string seq = "";

	for (int i = 1; i <= b; ++i) {
		for (int j = 1; j <= i; ++j)
			seq += (i + '0');
	}

	long long arr = atoll(seq.c_str());
	for (long long i = a - 1; i < b; ++i)
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