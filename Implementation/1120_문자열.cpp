#include <iostream>
#include <queue>
#include <string>

using namespace std;

int result = 0x7fffffff;

//최소
int min(int a, int b) {
	return a < b ? a : b;
}

//두 문자열 차이 수
//B를 고정시켜놓고 A를 적당히 움직이면서 
// 차이의 최소를 찾으면 됌 
// 왜냐면 앞뒤로 채우는 알파벳은 아무거나 채울 수 있으니 
// B와 동일한 알파벳을 추가한다고 가정하면 차이가 늘지 않기 때문입니다.
void get_diff_cnt(string a, string b) {
	int gap = b.length() - a.length();

	for (int i = 0; i <= gap; ++i) {
		int cnt = 0;
		for (int j = 0; j < a.length(); ++j) {
			if (a[j] != b[j + i])
				cnt++;
		}
		result = min(result, cnt);
	}
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string X, Y;
	cin >> X >> Y;
	get_diff_cnt(X, Y);
	cout << result << '\n';
	return 0;
}