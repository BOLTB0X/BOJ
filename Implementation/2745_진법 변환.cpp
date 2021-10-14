#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int pow(int a, int b) {
	int res = 1;
	if (b == 0) 
		return 1;
	else {
		for (int i = 0; i < a; i++)
			res *= a;
	}
	return res;
}

//b진수 n을 10진수로
int trans_dec(string n, int b) {
	int tot = 0;
	int size = n.length();

	for (int i = size - 1; i >= 0; i--) {
		//알파벳이면
		if (n[i] >= 'A' && n[i] <= 'Z') 
			//+10
			tot += (n[i] - 'A' + 10) * pow(b, size - 1 - i);
		
		else
			tot += (n[i] - '0') * pow(b, size - 1 - i);
	}
	return tot;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string N;
	int B;

	cin >> N >> B;

	int ret = trans_dec(N, B);
	cout << ret << '\n';
	return 0;
}
