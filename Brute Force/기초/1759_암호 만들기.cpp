#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//단어가 되는지 체크
void voca_check(vector<char>& str, vector<bool>& visited) {
	int moum_cnt = 0;
	int jaum_cnt = 0;

	for (int i = 0; i < str.size(); ++i) {
		if (visited[i]) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				moum_cnt++;
			else
				jaum_cnt++;
		}
	}

	if (jaum_cnt >= 2 && moum_cnt >= 1) {
		for (int i = 0; i < str.size(); ++i) 
			if (visited[i])
				cout << str[i];
		cout << '\n';
	}
	return;
}

//깊이우선탐색
void DFS(vector<char>& str, vector<bool>& visited, int L, int C, int cur, int depth) {
	if (depth == L) {
		voca_check(str,visited);
		return;
	}

	//조합 구현
	for (int i = cur; i < str.size(); ++i) {
		if (visited[i])
			continue;
		visited[i] = true;
		DFS(str, visited, L, C, i, depth + 1);
		visited[i] = false;
	}
	return;
}

void solution(void) {
	int L, C;
	
	//입력
	cin >> L >> C;
	vector<char> str(C, 0);
	for (int i = 0; i < C; ++i) 
		cin >> str[i];
	
	vector<bool> visited(C, false);

	//DFS를 위한 정렬
	sort(str.begin(), str.end());
	//호출
	DFS(str, visited, L, C, 0, 0);

	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}