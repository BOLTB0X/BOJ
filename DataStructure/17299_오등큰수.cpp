#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solution(void) {
	int n;
	
	cin >> n;
	//사이즈 조정
	vector<int> numbers(n + 1);
	vector<int> ngf(n + 1, -1);
	vector<int> f(1000001, 0);
	stack<int> st;

	//입력
	for (int i = 1; i <= n; ++i) {
		cin >> numbers[i];
		//등장 횟수 카운트
		f[numbers[i]]++;
	}

	for (int i = 1; i <= n; ++i) {
		//st의 top이 클 경우 크 카운트의 해당하는 인덱스의 값 할당
		while (!st.empty() && f[numbers[st.top()]] < f[numbers[i]]) {
			//교체
			ngf[st.top()] = numbers[i];
			st.pop();
		}
		st.push(i);
	}

	//출력
	for (int i = 1; i <= n; ++i)
		cout << ngf[i] << ' ';
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
