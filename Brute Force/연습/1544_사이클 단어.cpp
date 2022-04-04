#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 시계방향 회전 ->
string word_rotate(queue<char>& que) {
	string ret = "";

	for (int i = 0; i < que.size(); ++i) {
		ret += que.front();
		que.push(que.front());
		que.pop();
	}

	return ret;
}

// 같은지 판단
int is_Same_word(vector<string>& v, string word) {
	int size = v.size();
	queue<char> que;

	for (int i = 0; i < word.length(); ++i)
		que.push(word[i]);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			string rw = word_rotate(que); // 시계방향으로 하나씩 회전

			if (rw == v[i])
				return 1;

			// 안맞으니 다시 전진
			que.push(que.front());
			que.pop();
		}
	}

	return 0;
}

int solution(int n, vector<string>& words) {
	vector<string> answer;

	// 단어 탐색
	for (string& word : words) {
		if (answer.size() == 0)
			answer.push_back(word);

		else {
			// 읽을 수 없는 단어가 존재하면
			if (is_Same_word(answer, word) == 0)
				answer.push_back(word);
		}
	}

	return answer.size();
}

int main(void) {
	int n;
	vector<string> words;

	cin >> n;
	words.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> words[i];

	int ret = solution(n, words);
	cout << ret;

	return 0;
}
