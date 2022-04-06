#include <iostream>
#include <string>
#include <vector>
#define LL long long

using namespace std;

LL cnt = 0; // 카운트

// 백트래킹
void DFS(int n, int m, LL number) {
	if (number > m)
		return;

	if (n <= number && number <= m)
		cnt++;

	DFS(n, m, number * 10 + 4);
	DFS(n, m, number * 10 + 7);
	return;
}

LL solution(int n, int m) {
	LL answer = 0;

	DFS(n, m, 4);
	DFS(n, m, 7);
	
	answer = cnt;
	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	LL ret = solution(n, m);
	cout << ret;
	return 0;
}