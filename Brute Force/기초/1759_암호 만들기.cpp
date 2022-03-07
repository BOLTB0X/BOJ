#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector<char> com;
bool visited[15] = { false, };

void last_check(string str) {
	//모음갯수 및 자음 갯수 카운트
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

	//조건에 충족 되면
	if (moum_cnt >= 1 && cnt >= 2) {
		for (int i = 0; i < str.length(); i++) {
			//방문된것들만 출력
			if (visited[i])
				cout << str[i];
		}
		cout << '\n';
	}
	return;
}

void DFS(string s, int cur, int level) {
	//탈출 조건
	if (level == L) {
		last_check(s);
		return;
	}
	// 조합구하듯이 백 트래킹
	for (int i = cur; i < C; ++i) {
		if (visited[i])
			continue;
		visited[i] = true;
		DFS(s, i, level + 1);
		visited[i] = false;
	}
}

void solution(string str) {
	//깊이우선 이용
	sort(str.begin(), str.end());
	DFS(str, 0, 0);

	return;
}

int main(void) {
	//초기화 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> L >> C;
	string str;

	for (int i = 0; i < C; ++i) {
		char c;
		cin >> c;
		str += c;
	}

	solution(str);
	return 0;
}
