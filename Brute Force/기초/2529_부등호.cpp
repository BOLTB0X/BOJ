#include <iostream>
#include <string>
#include <vector>
#define LL long long

using namespace std;

vector<int> visited;
string max_result = "-9876543210";
string min_result = "9876543210";

void DFS(int n, vector<char>& paren, string seq, int level) {
	if (level == n + 1) {
		LL tmp = stoll(seq);
		if (stoll(max_result) < tmp)
			max_result = seq;
		if (stoll(min_result) > tmp)
			min_result = seq;
		return;
	}

	for (int i = 0; i < 10; ++i) {
		if (visited[i] == 0) {
			// 없는 경우
			if (level == 0) {
				visited[i] = 1;
				DFS(n, paren, seq + to_string(i), level + 1);
				visited[i] = 0;
			}
			else {
				// 필터링
				// level의 한 칸 전과 현재가 비교할 부등호
				if (paren[level - 1] == '<' && seq[level - 1] - '0' < i) {
					visited[i] = 1;
					DFS(n, paren, seq + to_string(i), level + 1);
					visited[i] = 0;
				}

	
				if (paren[level - 1] == '>' && seq[level - 1]  - '0' > i) {
					visited[i] = 1;
					DFS(n, paren, seq + to_string(i), level + 1);
					visited[i] = 0;
				}
			}
		}
	}
	return;
}

pair<string, string> solution(int n, vector<char>& paren) {
	pair<string, string> answer;
	visited.resize(10, 0); // 방문리스트

	DFS(n, paren, "", 0);

	answer.first = max_result;
	answer.second = min_result;
	return answer;
}

int main(void) {
	int n;
	vector<char> paren;

	cin >> n;
	paren.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> paren[i];

	pair<string, string> ret = solution(n, paren);
	cout << ret.first << '\n' << ret.second;
	return 0;
}
