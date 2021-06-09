#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<string> str(5); //문자열 벡터 생성
	string fbi = "FBI";
	vector<int> ans; //정답용 벡터

	for (auto& c : str) {
		cin >> c;
	}

	for (int i = 0; i < 5; i++) {
		if (str[i].find(fbi) != -1) {
			ans.push_back(i + 1);
		}
	}

	if (ans.size() == 0) 
		cout << "HE GOT AWAY!";
	else 
		for (auto c : ans) cout << c << " ";
	return 0;
}