#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(char& a, char& b) {
	return a > b;
}

string solution(string n) {
	string answer;
	// 30의 배수이기 위해서는
	// 1. 끝의 자리수가 0.
	// 2. 각 자리의 수의 합이 3의 배수.

	int tot = 0;
	for (int i = 0; i < n.length(); ++i) 
		tot += (n[i] - '0');
	
	sort(n.begin(), n.end(), compare); // 내림차순 정렬
	// 조건 충족 X
	if (tot % 3 != 0 || n[n.length() -1] != '0')
		answer = "-1";
	else 
		answer = n;

	return answer;
}

int main(void) {
	string n;
	cin >> n;

	string ret = solution(n);
	cout << ret;
	return 0;
}