#include <iostream>
#include <string>
using namespace std;

int T; //�׽�Ʈ ����

void solution() {
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int a, b;
		string answer = "";
		cin >> a >> b;
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			
			int temp = s[j] - 'A';
			if (temp >= 0 && temp < 26) {
				answer += (((a * temp + b)%26)+65);
			}
		}
		cout << answer << endl;
	}
}

int main() {
	solution();
	return 0;
}