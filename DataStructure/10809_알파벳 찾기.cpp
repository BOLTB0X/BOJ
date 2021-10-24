#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct INFO {
	char ch;
	int cur;
};

//알파벳 체크
void check_location(vector<INFO>& v, char ch, int idx) {
	//알파벳 갯수를 체크해준다.
	for (int i = 0; i < v.size(); ++i)
		if (v[i].ch == ch && v[i].cur == -1)
			v[i].cur = idx;

	return;
}

void solution(void) {
	string str;
	vector<INFO> alp;
	
	//알파벳 벡터 초기화
	for (int i = 97; i <= 122; ++i)
		alp.push_back({ (char)i,-1 });

	cin >> str;

	//각 사용된 알파벳 위치 체크
	for (int i = 0; i < str.length(); ++i)
		check_location(alp, str[i], i);

	//출력
	for (int i = 0; i < alp.size(); ++i)
		cout << alp[i].cur << ' ';
	cout << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//해결
	solution();
	return 0;
}