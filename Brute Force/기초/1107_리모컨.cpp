#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
vector<int> numbers;
vector<bool> visited;

int MIN(int a, int b) {
	return a < b ? a : b;
}

bool is_broken(int cur) {
	string cur_number = to_string(cur);
	int size = cur_number.size();

	for (int i = 0; i < size; ++i) {
		//고장난 번호이면
		int idx = cur_number[i] - '0';
		if (visited[idx])
			return 0;
	}

	return 1;
}

int solution(void) {
	//1씩 증가시키는 방법이 최대 횟수
	int answer = abs(n - 100);
	
	for (int i = 0; i <= 1000000; ++i) {
		if (is_broken(i)) {
			int tmp = abs(n - i) + to_string(i).length();
			answer = MIN(answer, tmp);
		}
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	numbers.resize(n + 1, 0);
	visited.resize(10, false);
	
	cin >> m;
	
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		visited[x] = 1;
	}

	int ret = solution();
	cout << ret;

	return 0;
}