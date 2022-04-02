#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> alp_cnt(26, 0); // 알파벳 카운트

bool impossible_Palin(void) {
	int cnt = 0;

	for (int i = 0; i < 26; ++i) {
		if (alp_cnt[i] % 2 == 1)
			cnt++;
	}

	// 홀수인데 갯수가 2이상이면 
	return cnt > 1;
}

string solution(string str) {
	string answer;
	int size = str.length();

	for (int i = 0; i < size; ++i)
		alp_cnt[str[i] - 'A']++;

	if (impossible_Palin())
		answer = "I'm Sorry Hansoo";

	// 알파벳순으로 해야하므로
	else {
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < alp_cnt[i] / 2; ++j)
				answer += i + 'A';
		}

		// 홀수 개는 중앙에
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