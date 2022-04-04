#include <iostream>
#include <string> // to_string, atoi
#include <vector>
#define LL long long

using namespace std;

char number[10] = { '0','1','2','3','4','5','6','7','8','9' };
vector<int> visited(10, 0); // 방문리스트
string max_result = "-9876543210";
string min_result = "9876543210";

// 깊이우선탐색
void DFS(int n, vector<char>& v, string seq, int level) {
	// 부등호에 들어가야하는 정수는 n + 1
	if (seq.length() > n) {
		LL tmp = stoll(seq);
		if (stoll(max_result) < tmp)
			max_result = seq;
		if (stoll(min_result) > tmp)
			min_result = seq;
		return;
	}

	// 0부터 9까지 순차적으로
	for (int i = 0; i < 10; ++i) {
		if (visited[i] == 0) {
			// 없는 경우
			if (level == 0) {
				visited[i] = 1;
				DFS(n, v, seq + number[i], level + 1);
				visited[i] = 0;
			}

			else {
				// 큰 경우
				if (v[level - 1] == '>' && seq[level - 1] > number[i]) {
					visited[i] = 1;
					DFS(n, v, seq + number[i], level + 1);
					visited[i] = 0;
				}

				// 작은 경우
				else if (v[level - 1] == '<' && seq[level - 1] < number[i]) {
					visited[i] = 1;
					DFS(n, v, seq + number[i], level + 1);
					visited[i] = 0;
				}
			}
		}
	}
	return;
}

pair<string, string> solution(int k, vector<char>& v) {
	pair<string, string> answer;

	//백트래킹
	DFS(k, v, "", 0);
	answer.first = max_result;
	answer.second = min_result;
	return answer;
}

int main(void) {
	int k;
	vector<char> input;

	cin >> k;
	input.resize(k);
	for (int i = 0; i < k; ++i)
		cin >> input[i];

	pair<string, string> ret = solution(k, input);
	cout << ret.first << "\n" << ret.second << '\n';
	return 0;
}
