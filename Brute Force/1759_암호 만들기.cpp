#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L, C;

//마지막 체크
void last_check(string str, bool* visited) {
	int moum_cnt = 0;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (visited[i]) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
				|| str[i] == 'o' || str[i] == 'u')
				moum_cnt++;
			else
				cnt++;
		}
	}
	if (moum_cnt >= 1 && cnt >= 2) {
		for (int i = 0; i < str.length(); i++) {
			if (visited[i])
				cout << str[i];
		}
		cout << '\n';
	}
	return;
}

//깊이우선
void DFS(string str, bool* visited, int cur, int depth) {
	if (depth == L) {
		last_check(str, visited);
		return;
	}
	for (int i = cur; i < str.length(); i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		DFS(str, visited, i, depth + 1);
		visited[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;
	string str;
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		str += c;
	}
	bool visited[15] = { false, };
	sort(str.begin(), str.end());
	DFS(str, visited, 0, 0);
	return 0;
}