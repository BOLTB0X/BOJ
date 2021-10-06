#include <iostream>

using namespace std;

//�ִ�
int max(float a, float b) {
	return a > b ? a : b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double result = -1, tot;
	
	//�Է�
	cin >> n;
	//�����Ҵ�
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//���ҵ��� �Ҽ������� �������
	//�� �۾����⵵�ϰ� Ŀ���⵵ �ϹǷ�
	//����Ž��
	for (int i = 0; i < n; i++) {
		tot = 1;
		for (int j = i; j < n; j++) {
			tot *= arr[j];
			result = max(result, tot);
		}
	}
	printf("%.3f\n", result);
	delete[] arr;
	return 0;
}