#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> alp_cnt(26, 0); // ���ĺ� ī��Ʈ

bool impossible_Palin(void) {
	int cnt = 0;

	for (int i = 0; i < 26; ++i) {
		if (alp_cnt[i] % 2 == 1)
			cnt++;
	}

	// Ȧ���ε� ������ 2�̻��̸� 
	return cnt > 1;
}

string solution(string str) {
	string answer;
	int size = str.length();

	for (int i = 0; i < size; ++i)
		alp_cnt[str[i] - 'A']++;

	if (impossible_Palin())
		answer = "I'm Sorry Hansoo";

	// ���ĺ������� �ؾ��ϹǷ�
	else {
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < alp_cnt[i] / 2; ++j)
				answer += i + 'A';
		}

		// Ȧ�� ���� �߾ӿ�
		for (int i = 0; i < 26; ++i) {
			if (alp_cnt[i] % 2)
				answer += i + 'A';
		}

		for (int i = 25; i >= 0; --i) {
			for (int j = 0; j < alp_cnt[i] / 2; ++j)
				answer += i + 'A';
		}
	}

	return answer;
}

int main(void) {
	string input;

	cin >> input;

	string ret = solution(input);
	cout << ret;

	return 0;
}