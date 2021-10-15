#include <iostream>
#include <string>

using namespace std;

int result = 51;

int min(int a, int b) {
	return a < b ? a : b;
}
//�� ���ڿ� ���� ��
//B�� �������ѳ��� A�� ������ �����̸鼭 
// ������ �ּҸ� ã���� �� 
// �ֳĸ� �յڷ� ä��� ���ĺ��� �ƹ��ų� ä�� �� ������ 
// B�� ������ ���ĺ��� �߰��Ѵٰ� �����ϸ� ���̰� ���� �ʱ� ����.
void solution(string a, string b) {
	int gap = b.length() - a.length();

	for (int i = 0; i <= gap; i++) {
		int cnt = 0;
		for (int j = 0; j < a.length(); ++j) {
			//i��ŭ �������鼭 ��
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