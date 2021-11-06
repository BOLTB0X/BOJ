#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//1순위 짧은 것
//2순위 사전순
bool compare(string a, string b) {
	//길이
	if (a.length() < b.length())
		return 1;
	else if (b.length() < a.length())
		return 0;
	else
		return a < b; //사전순
}

void solution(void) {
	int n;
	cin >> n;
	vector<string> str;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		str.push_back(word);
	}
	//정렬
	sort(str.begin(),str.end(),compare);

	//출력
	for (int i = 0; i < n; i++) {
		//중복 제거
		if (i>0 && str[i - 1] == str[i])
			continue;
		cout << str[i] << '\n';
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