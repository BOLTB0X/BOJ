#include <iostream>
#include <string>

using namespace std;

string solution(int n, int b) {
	string answer = "";
	string tmp_answer = "";
	
	//진법변환 시작
	while (n >= 1) {
		int r = n % b;
		//즉 알파벳이 필요없는 경우
		if (r < 10)
			tmp_answer += (char)(r + '0');
		//10초과시
		else
			tmp_answer += (char)(r - 10 + 'A');
		n /= b;
	}
	//tmp_answer에 진법변환한 것이 뒤집어져있기에
	for (int i = tmp_answer.length() - 1; i >= 0; i--) {
		answer += tmp_answer[i];
	}
	return answer;
}

int main(void) {
	int n, b;
	cin >> n >> b;
	cout << solution(n, b) << '\n';
	return 0;
}
