#include <iostream>
#include <string>

using namespace std;

int result = 51;

int min(int a, int b) {
	return a < b ? a : b;
}
//두 문자열 차이 수
//B를 고정시켜놓고 A를 적당히 움직이면서 
// 차이의 최소를 찾으면 됌 
// 왜냐면 앞뒤로 채우는 알파벳은 아무거나 채울 수 있으니 
// B와 동일한 알파벳을 추가한다고 가정하면 차이가 늘지 않기 때문.
void solution(string a, string b) {
	int gap = b.length() - a.length();

	for (int i = 0; i <= gap; i++) {
		int cnt = 0;
		for (int j = 0; j < a.length(); ++j) {
			//i만큼 떨어지면서 비교
			if (a[j] != b[j + i])
				cnt++;
		}
		result = min(result, cnt);
	}

	cout << result << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string A, B;
	cin >> A >> B;

	solution(A, B);
	return 0;
}