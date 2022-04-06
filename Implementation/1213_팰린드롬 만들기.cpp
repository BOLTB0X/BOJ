#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> alp_cnt(26, 0); // 카운트

int is_Process(void) {
	int cnt = 0;

	for (int i = 0; i < 26; ++i)
		if (alp_cnt[i] % 2 == 1)
			cnt++;

	return cnt > 1;
}

string solution(string str) {
	string answer;
	int size = str.length();

	for (int i = 0; i < size; ++i)
		alp_cnt[str[i] - 'A']++;

	if (is_Process() == 1) 
		answer = "I'm Sorry Hansoo";
	else {
		// 앞
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < alp_cnt[i] / 2; ++j)
				answer += (i + 'A');
		}

		// 중앙
		for (int i = 0; i < 26; ++i) {
			if (alp_cnt[i] % 2 == 1)
				answer += (i + 'A');
		}

		// 앞
		for (int i = 25; i >= 0; --i) {
			for (int j = 0; j < alp_cnt[i] / 2; ++j)
				answer += (i + 'A');
		}
	}

	return answer;
}

int main(void) {
	string str;

	cin >> str;

	string ret = solution(str);
	cout << ret;
	return 0;
}
