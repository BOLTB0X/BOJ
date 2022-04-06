#include <iostream>
#include <string>
#include <vector>

using namespace std;

int result = -1;
vector<int> visited;

int Max(int a, int b) {
	return a > b ? a : b;
}

void DFS(string A, string B, string C, int level) {
	if (level == A.length()) {
		int number = stoi(C);
		if (A !=C && number < stoi(B)) 
			result = Max(result, number);
		return;
	}

	for (int i = 0; i < A.length(); ++i) {
		if (visited[i] == 1)
			continue;

		if (C.length() == 0 && A[i] == '0')
			continue;
		visited[i] = 1;
		DFS(A, B, C + A[i], level + 1);
		visited[i] = 0;
	}
	return;
}

int solution(string A, string B) {
	int answer = -1;

	visited.resize(A.length(), 0); // 방문리스트 초기화
	DFS(A, B, "", 0);
	if (result != -1)
		answer = result;
	return answer;
}

int main(void) {
	string A, B;

	cin >> A >> B;
	int ret = solution(A, B);
	cout << ret;

	return 0;
}