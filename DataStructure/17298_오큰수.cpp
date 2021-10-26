#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solution(void) {
	int n;

	cin >> n;

	//사용할 벡터 크기 사이즈 조정
	vector<int> numbers(n + 1);
	vector<int> nge(n + 1, -1);
	stack<int> st;

	//입력
	for (int i = 1; i <= n; ++i)
		cin >> numbers[i];

	//순회
	for (int i = 1; i <= n; ++i) {
		//스택이 top이 다 더 커질 때까지 스택을 pop
		while (!st.empty() && numbers[st.top()] < numbers[i]) {
			nge[st.top()] = numbers[i];
			st.pop();
		}
		st.push(i);
	}

	//출력
	for (int i = 1; i <= n; ++i)
		cout << nge[i] << ' ';
	cout << '\n';

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
