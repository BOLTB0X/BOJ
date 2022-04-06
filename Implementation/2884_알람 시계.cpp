#include <iostream>
#include <string>
using namespace std;

string solution(int H, int M) {
	string answer = "";
	int ah = 0, am = 0;

	if (45 <= M) {
		am = M - 45;
		ah = H;
	}

	else {
		am = 60 + M - 45;
		ah = H - 1;
		if (ah < 0) 
			ah = 23;
	}

	answer += to_string(ah);
	answer += ' ';
	answer += to_string(am);

	return answer;
}
int main(void) {
	int H, M;

	cin >> H >> M;

	string ret = solution(H, M);
	cout << ret;
	return 0;
}