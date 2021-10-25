#include <iostream>
#include <vector>
#include <string>

using namespace std;

//개수와 문자 
struct INFO {
	int cnt;
	char c;
};

//알파벳 체크
void check_cnt(vector<INFO> &v,char ch) {
	//알파벳 갯수를 체크해준다.
	for (int i = 0; i < v.size(); ++i) 
		if (v[i].c == ch)
			v[i].cnt++;

	return;
}

void solution(void) {
	string str;
	vector<INFO> alp;

	//알파벳벡터 생성 및 초기화
	for (int i = 97; i <= 122; i++) 
		alp.push_back({ 0,(char)i });

	cin >> str;

	//각 사용된 알파벳 개수 체크
	for (int i = 0; i < str.length(); ++i) 
		check_cnt(alp, str[i]);
	
	//출력
	for (int i = 0; i < alp.size(); ++i)
		cout << alp[i].cnt << ' ';
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