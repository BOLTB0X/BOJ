#include <iostream>
#include <queue>
#include <string>

using namespace std;

int result = 0x7fffffff;

//�ּ�
int min(int a, int b) {
	return a < b ? a : b;
}

//�� ���ڿ� ���� ��
//B�� �������ѳ��� A�� ������ �����̸鼭 
// ������ �ּҸ� ã���� �� 
// �ֳĸ� �յڷ� ä��� ���ĺ��� �ƹ��ų� ä�� �� ������ 
// B�� ������ ���ĺ��� �߰��Ѵٰ� �����ϸ� ���̰� ���� �ʱ� �����Դϴ�.
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
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string X, Y;
	cin >> X >> Y;
	get_diff_cnt(X, Y);
	cout << result << '\n';
	return 0;
}