#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string n;
int b;
int answer;

void solution(string n, int b) {
	
	int count = 0;
	for (int i = n.length() - 1; i >= 0; i--) {
		int temp = n[i];
		if (temp >= 'A' && temp <= 'Z') {
			answer += (temp - 'A' + 10) * ((int)pow(b, count));
		}
		else {
			answer += (temp-'0')* ((int)pow(b, count));
		}
		count++;
	}
	cout << answer << '\n';
}

int main(void) {
	cin >> n >> b;
	solution(n,b);
	return 0;
}