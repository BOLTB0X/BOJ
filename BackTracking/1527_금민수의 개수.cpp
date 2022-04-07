#include <iostream>
#include <string>
#include <vector>
#define LL long long

using namespace std;

LL cnt = 0;

// 깊이우선탐색
void DFS(LL A, LL B, LL number) {
	if (B < number)
		return;

	if (A <= number && B >= number) 
		cnt++;
	
	DFS(A, B, number * 10 + 4);
	DFS(A, B, number * 10 + 7);
	return;
}

LL solution(LL A, LL B) {
	LL answer = 0;

	DFS(A, B, 4);
	DFS(A, B, 7);

	answer = cnt;
	return answer;
}

int main(void) {
	LL A, B;

	cin >> A >> B;
	LL ret = solution(A, B);
	cout << ret;
	return 0;
}
