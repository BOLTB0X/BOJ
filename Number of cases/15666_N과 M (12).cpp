#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> com;
set<vector<int>> ans_com;

//깊이우선탐색
void DFS(vector<int>& arr, int n, int m, int cur, int depth) {
	//탈출조건
	if (com.size() == m) {
		vector<int> tmp;
		for (int i = 0; i < com.size(); ++i)
			tmp.push_back(com[i]);
		//나온 벡터를 set에 삽입
		ans_com.insert(tmp);
		return;
	}

	for (int i = cur; i < arr.size(); ++i) {
		com.push_back(arr[i]);
		DFS(arr, n, m, i, depth + 1);
		com.pop_back();
	}
	return;
}

void solution(void) {
	int n, m;

	//입력
	cin >> n >> m;

	//벡터 사이즈 설정
	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	//오름차순
	sort(arr.begin(), arr.end());

	//탐색 시작
	DFS(arr, n, m, 0, 0);

	//출력
	for (auto a : ans_com) {
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
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