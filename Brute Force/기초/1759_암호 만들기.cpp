#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort

using namespace std;

vector<int> visited;
vector<string> result;

int check_Voca(string voca) {
	int size = voca.length();
	int m_cnt = 0;
	int j_cnt = 0;
	for (char& v : voca) {
		if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
			m_cnt++;
		else
			j_cnt++;
	}

	return m_cnt >= 1 && j_cnt >= 2 ? 1 : 0;
}

void DFS(int L, int C, string words, string str, int cur, int level) {
	if (level == L) {
		if (check_Voca(str) == 1)
			result.push_back(str);
		return;
	}

	for (int i = cur; i < C; ++i) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		str.push_back(words[i]);
		DFS(L, C, words, str, i, level + 1);
		str.pop_back();
		visited[i] = 0;
	}
}

vector<string> solution(int L, int C, string words) {
	vector<string> answer;
	visited.resize(C + 1, 0); // 방문 리스트 초기화
	sort(words.begin(), words.end()); // 오름차순 정렬
	DFS(L, C, words, "", 0, 0);
	answer = result;

	return answer;
}

int main(void) {
	int L, C;
	string words;
	cin >> L >> C;

	for (int i = 0; i < C; ++i) {
		char ch;
		cin >> ch;
		words += ch;
	}

	vector<string> ret = solution(L, C, words);
	for (string& r : ret) {
		cout << r << '\n';
	}
}
