#include<iostream>
#include<string>
#include<stack>

using namespace std;

string solution(string str) {
	string answer = "";
	stack<char> st;
	int size = str.length();

	for (int i = 0; i < size; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			answer += str[i];

		else {
			// ¿ÀÇÂ
			if (str[i] == '(') 
				st.push('(');
			
			else if (str[i] == '*' || str[i] == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					answer += st.top();
					st.pop();
				}

				st.push(str[i]);
			}
			
			else if (str[i] == '+' || str[i] == '-') {
				while (!st.empty() && st.top() != '(') {
					answer += st.top();
					st.pop();
				}

				st.push(str[i]);
			}
			
			else if (str[i] == ')') {
				while (!st.empty() && st.top() != '(') {
					answer += st.top();
					st.pop();
				}
				st.pop(); // (
			}

		}
	}

	while (!st.empty()) {
		answer += st.top();
		st.pop();
	}
	return answer;
}

int main(void) {
	string str;

	cin >> str;
	string ret = solution(str);
	cout << ret;
	return 0;
}