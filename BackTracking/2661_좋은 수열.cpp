#include <iostream>
#include <string>

using namespace std;

int flag = 0;
string result;

// ���� �������� �Ǵ�
int is_Good_sq(string sq) {
	int size = sq.length(); // ����

	// �¿� ����ó�� �ݺ��Ǿ���ϴµ� 2���� �ڸ��µ� ������ 0 ��ȯ
	for (int i = 2; i <= size; i += 2) {
		string cmp1 = sq.substr(size - (i / 2), i / 2); // ��
		string cmp2 = sq.substr(size - i, i / 2); // ��

		// ���ٸ�
		if (cmp1 == cmp2)
			return  0;
	}
	return 1;
}

void DFS(string number, int n) {
	// ���� ���� ���
	if (flag == 1)
		return;

	// Ż������
	if (number.length() == n) {
		result = number;
		flag = 1;
		// atoi�� ������ ��ȯ�� �ּڰ��� ���ϴ� ��ĵ� ��
		return;
	}

	// 1���� ����������
	// ó������ �����ϴ� ������ ���� ���� ���� ����
	for (int i = 1; i <= 3; ++i) {
		number.push_back(i + '0'); // ����
		if (is_Good_sq(number) == 1) // ���� ���� ��� �ٽ� DFS ȣ��
			DFS(number, n);
		number.pop_back(); // ��
	}
	return;
}

string solution(int n) {
	string answer;

	//��Ʈ��ŷ ����
	DFS("", n);
	answer = result;
	return answer;
}

int main(void) {
	int n;
	cin >> n;

	string ret = solution(n);
	cout << ret;
	return 0;
}