#include <iostream>
#include <string>

using namespace std;


string solution(int n, int b) {
	string answer = "";
	string tmp_answer = "";
	
	//������ȯ ����
	while (n >= 1) {
		int r = n % b;
		//�� ���ĺ��� �ʿ���� ���
		if (r < 10)
			tmp_answer += (char)(r + '0');
		//10�ʰ���
		else
			tmp_answer += (char)(r - 10 + 'A');
		n /= b;
	}
	//tmp_answer�� ������ȯ�� ���� ���������ֱ⿡
	for (int i = tmp_answer.length() - 1; i >= 0; i--) {
		answer += tmp_answer[i];
	}
	return answer;
}

int main(void) {
	int n, b;
	cin >> n >> b;
	cout << solution(n, b) << '\n';
	return 0;
}
