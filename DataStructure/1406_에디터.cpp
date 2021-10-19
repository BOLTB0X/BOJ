#include <iostream>
#include <string>
#include <stack>

using namespace std;

void solution(void) {
	string str;
	int T;
	stack<char> L;
	stack<char> R;

	cin >> str;
	for (int i = 0; i < str.length(); ++i)
		L.push(str[i]);

	cin >> T;
	while (T--) {
		char cmm;
		cin >> cmm;
		
		//삽입
		if (cmm == 'P') {
			char c;
			cin >> c;
			L.push(c);
		}

		//커서 왼쪽으로 옮김
		else if (cmm == 'L') {
			if (L.empty())
				continue;
			else {
				R.push(L.top());
				L.pop();
			}
		}

		//삭제
		else if (cmm == 'B') {
			if (L.empty())
				continue;
			else
				L.pop();
		}

		//오른쪽으로 한칸 옮김
		else if (cmm == 'D') {
			if (R.empty())
				continue;
			else {
				L.push(R.top());
				R.pop();
			}
		}
	}
	//왼쪽 스택 오른쪽 스택에 옮겨줌
	while (!L.empty()) {
		R.push(L.top());
		L.pop();
	}
	
	//선입후출이므로
	//R의 상단을 뽑음
	while (!R.empty()) {
		cout << R.top();
		R.pop();
	}
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