#include <iostream>
#include <string>
#include <vector>
#include <queue> // 큐

using namespace std;

string arr[51];

string rotate_word(queue<char>& que) {
	string ret = "";

	for (int i = 0; i < que.size(); ++i) {
		ret += que.front();
		que.push(que.front());
		que.pop();
	}

	return ret;
}

// 같은 단어인지 판단
int is_Same(vector<string>& v, string word, queue<char>& que) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < word.length(); ++j) {
			string rw = rotate_word(que);

			if (rw == v[i])
				return 1;
			
			que.push(que.front());
			que.pop();
		}
	}
	return 0;
}

int solution(int n) {
	int answer = 0;
	vector<string> v;

	for (int i = 0; i < n; ++i) {
		string word = arr[i];

		if (v.size() == 0)
			v.push_back(word);

		else {
			queue<char> que;

			for (int j = 0; j < word.length(); ++j)
				que.push(word[j]);

			// 다른 단어면
			if (is_Same(v, word, que) == 0)
				v.push_back(word);
		}
	}

	answer = v.size();
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret = solution(n);
	cout << ret;

	return 0;
}