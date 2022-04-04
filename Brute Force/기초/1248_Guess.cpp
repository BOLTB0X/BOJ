#include <iostream>
#include <vector>

using namespace std;

int flag = 0;
char board[11][11];
vector<int> result;

int is_Process(vector<int>& seq, int idx) {
	int tot = 0;
	
	// 
	for (int i = idx; i >= 0; --i) {
		tot += seq[i];

		if (board[i][idx] == '+' && tot <= 0)
			return 0;

		else if (board[i][idx] == '-' && tot >= 0)
			return 0;

		else if (board[i][idx] == '0' && tot != 0)
			return 0;
	}

	return 1;
}

void DFS(int n, vector<int>& seq, int level) {
	// 답이 나왔다면
	if (flag == 1)
		return;

	// 탈출 조건
	if (level == n) {
		result = seq;
		flag = 1;
		return;
	}

	for (int i = -10; i <= 10; ++i) {
		seq.push_back(i);

		if (is_Process(seq, level) == 1)
			DFS(n, seq, level + 1);
		seq.pop_back();
	}
	return;
}

vector<int> solution(int n, string guess_cmd) {
	vector<int> answer;
	vector<int> seq; // 수열
	int idx = 0;

	// 명령어를 옭김
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j)
			board[i][j] = guess_cmd[idx++];
	}

	DFS(n, seq, 0);
	answer = result;

	return answer;
}

int main(void) {
	int n;
	string guess_cmd;

	cin >> n;
	cin >> guess_cmd;
	vector<int> ret = solution(n, guess_cmd);
	for (int& r : ret)
		cout << r << ' ';
	return 0;
}
