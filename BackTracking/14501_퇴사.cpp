#include <iostream>
#include <vector>

using namespace std;

int n, result = -0x7fffffff;
vector<int> days;
vector<int> pay;

//�ִ񰪹�ȯ
int max(int a, int b) {
	return a > b ? a : b;
}

void DFS(int cur_day, int add_pay, int tot) {
	//Ż�� ����
	if (cur_day == n + 1) {
		result = max(result, tot);
		return;
	}
	
	//���� ��û �Ѿ� ���ٸ�
	else if (cur_day > n + 1) {
		result = max(result, tot - add_pay);
		return;
	}

	//�� ���� DFSȣ��
	for (int i = cur_day; i <= n; ++i)
		DFS(i + days[i], pay[i], tot + pay[i]);
}

void solution(void) {
	cin >> n;

	//���� ������ ����
	days.resize(n + 1, 0);
	pay.resize(n + 1, 0);

	for (int i = 1; i <= n; ++i) 
		cin >> days[i] >> pay[i];
	
	//���̿켱Ž��
	DFS(1, 0, 0);

	//���
	cout << result << '\n';
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