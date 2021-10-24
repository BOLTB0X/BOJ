#include <iostream>
#include <stack>
#include <vector>

using namespace std;
 
void solution(void) {
	int n;
	stack<int> st;
	vector<char> answer;

	cin >> n;
	//스택의 상단 값
	int st_top = 0;

	while (n--) {
		int x;
		cin >> x;

		if (x > st_top) {
			while (x > st_top) {
				st.push(++st_top);
				//push한 만큼 +
				answer.push_back('+');
			}
			st.pop();
			answer.push_back('-');
		}

		//x가 상단값보다 크거나 같은 경우
		else {
			bool flag = false;
			if (!st.empty()) {
				//상단이 x이면
				if (x == st.top()) 
					flag = true;
				st.pop();
				answer.push_back('-');
			}

			//만약 찾지 못한다면
			if (!flag) {
				cout << "NO" << '\n';
				return ;
			}
		}
	}

	//answer 하나씩 pop
	for (auto a : answer)
		cout << a << '\n';
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
