#include <iostream>
#include <stack>
#include <string>

using namespace std;

void solution(void) {
	int T;
	stack<char> st;

	cin >> T;

	//입력 버퍼 비우기
	cin.ignore();
	while (T--) {
		string words;
		//띄어쓰기 까지 입력
		getline(cin, words);
		//출력을 맞추기 위해
		words += " ";

		//순회
		for (int i = 0; i < words.length(); ++i) {
			//공백이 스택의 pop 신호
			if (words[i] == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ' ';
			}
			//스택에 삽입
			else 
				st.push(words[i]);
		}
		cout << '\n';
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
