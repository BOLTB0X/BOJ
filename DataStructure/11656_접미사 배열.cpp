#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution(void) {
	string str;
	vector<string> result;

	cin >> str;
	//substr이용하여 결과벡터에 삽입
	for (int i = 0; i < str.length(); ++i) {
		string tmp = str.substr(i);
		result.push_back(tmp);
	}
	
	//sort함수 이용
	sort(result.begin(), result.end());

	//정답 출력
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << '\n';

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