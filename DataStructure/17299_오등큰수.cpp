#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solution(void) {
	int n;
	
	//입력
	cin >> n;
	vector<int> numbers(n + 1);
	vector<int> ngf(n + 1, -1);
	vector<int> f(1000001, 0);
	stack<int> st;

	for (int i = 1; i <= n; ++i) {
		cin >> numbers[i];
		f[numbers[i]]++;
	}

	for (int i = 1; i <= n; ++i) {
		//오른쪽에 있으면서 등장한 횟수가 클 경우
		while (!st.empty() && f[numbers[st.top()]] < f[numbers[i]]) {
			//교체
			ngf[st.top()] = numbers[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; ++i) {
		cout << ngf[i] << ' ';
	}
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