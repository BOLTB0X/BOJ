#include <iostream>

using namespace std;

int result;

//���� �켱 Ž��
void DFS(int n, int tot) {
	//Ż������ == �ѱ��
	if (tot > n)
		return;
	//�ȴٸ�
	if (tot == n)
		result++;
	for (int i = 1; i <= 3; ++i)
		DFS(n, tot + i);
	return;
}

void solution(void) {
	int T;
	cin >> T;

	while (T--) {
		//�Է�
		int n;
		cin >> n;

		//DFS�� �ʱ�ȭ 
		result = 0;
		//DFS ȣ��
		DFS(n, 0);

		//���
		cout << result << '\n';
	}
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}