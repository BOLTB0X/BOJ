#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solution(void) {
	int n;
	cin >> n;

	//정답용
	vector<int> nge(n + 1, -1);
	//스택
	stack<int> st;

	//동적할당
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	for (int i = 1; i <= n; ++i) {
		//스택이 top이 초록 막대보다 더 커질 때까지 스택을 pop
		while (!st.empty() && arr[st.top()] < arr[i]) {
			nge [st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	//출력
	for (int i = 1; i <= n; ++i)
		cout << nge[i] << ' ';
	cout << '\n';

	//해제
	delete[] arr;
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