#include <iostream>
#include <string>
using namespace std;

int n;
int b;
string answer="";

void solution(int n, int b) {
	string temp = "";
	while (n>=1) {
		int r = n % b;
		if (r < 10)
			temp += (char)(r + '0');
		else
			temp += (char)(r - 10 + 'A');
		n /= b;
	}
	for (int i = temp.length() - 1; i >= 0; i--) {
		answer += temp[i];
	}
	cout << answer << '\n';
}
int main(void) {
	cin >> n >> b;
	solution(n,b);
	return 0;
}