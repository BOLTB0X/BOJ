#include <iostream>
#include <string>
#include <vector>

using namespace std;

int result = -1;
vector<int> visited;

void DFS(string A, string B, string seq, int level) {
	// 탈출조건
	// 어차피 A와 B는 길이가 같음
	if (level == A.length()) {
		int number = stoi(seq);
		if (seq != A && number < stoi(B)) 
			result = number > result ? number : result;
		return;
	}

	for (int i = 0; i < A.length(); ++i) {
		if (visited[i] == 1)
			continue;

		if (seq.length() == 0 && A[i] == '0')
			continue;

		visited[i] = 1;
		DFS(A, B, seq + A[i], level + 1);
		visited[i] = 0;
	}
	return;
}

int solution(int A, int B) {
	int answer = -1;
	string str_A = to_string(A);
	string str_B = to_string(B);
	visited.resize(str_A.length(), 0); // 방문리스트

	DFS(str_A, str_B, "", 0);
	if (result != -1)
		answer = result;
	return answer;
}

int main(void) {
	int A, B;

	cin >> A >> B;
	int ret = solution(A, B);
	cout << ret;

	return 0;
}
