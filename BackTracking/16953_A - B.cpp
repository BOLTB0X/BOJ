#include <iostream>
#define LL long long

using namespace std;

int result = 1e9;

LL Min(LL a, LL b) {
	return a < b ? a : b;
}

void DFS(LL cur, LL target, LL level) {
	// 크다면
	if (target < cur)
		return;

	// 도달하면
	if (cur == target) {
		result = Min(result, level);
		return;
	}

	DFS(cur * 2, target, level + 1);
	DFS((cur * 10) + 1, target, level + 1);
	return;
}

LL solution(LL A, LL B) {
	LL answer = -1;

	DFS(A, B, 1);
	if (result != 1e9)
		answer = result;
	
	return answer;
}

int main(void) {
	LL A, B;

	cin >> A >> B;
	LL ret = solution(A, B);
	cout << ret;

	return 0;
}