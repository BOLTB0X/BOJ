#include <iostream>
#include <cmath>

using namespace std;

//�ִ밪 ����
#define MAX 1000000

//���ڹ迭 ����
int numbers[MAX] = { 0, };

//����
void init(void) {
	//������ 
	numbers[0] = numbers[1] = 1;
	for (int i = 2; i <= (int)sqrt(MAX); ++i) {
		for (int j = i * i; j <= MAX; j += i) {
			//1�̸� �Ҽ��� �ƴ�
			if (numbers[j] % i == 0)
				numbers[j] = 1;
		}
	}
	return;
}

void solution(void) {
	//������ ������ ���� ����
	init();

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int cnt = 0;
		//��Ƽ�� ���ϱ�
		for (int i = n / 2; i > 0; i--) {
			//�߰� ī��Ʈ
			if (numbers[i] != 1 && numbers[n - i] != 1) {
				cnt++;
			}
		}
		cout << cnt << '\n';
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