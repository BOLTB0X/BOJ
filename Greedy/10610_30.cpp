#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(char& a, char& b) {
	return a > b;
}

string solution(string n) {
	string answer;
	// 30�� ����̱� ���ؼ���
	// 1. ���� �ڸ����� 0.
	// 2. �� �ڸ��� ���� ���� 3�� ���.

	int tot = 0;
	for (int i = 0; i < n.length(); ++i) 
		tot += (n[i] - '0');
	
	sort(n.begin(), n.end(), compare); // �������� ����
	// ���� ���� X
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