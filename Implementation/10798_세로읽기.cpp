#include <iostream>
#include <vector>

using namespace std;

string solution(string str[]) {
	string answer = "";
	vector<vector<char>> board(5, vector<char>(15, 0));

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < str[i].length(); ++j)
			board[i][j] = str[i][j];
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[j][i] == 0)
				continue;
			answer += board[j][i];
		}
	}

	return answer;
}

int main(void) {
	string str[15];
	for (int i = 0; i < 5; ++i) 
		cin >> str[i];
	
	string ret = solution(str);
	cout << ret;
	return 0;
}
