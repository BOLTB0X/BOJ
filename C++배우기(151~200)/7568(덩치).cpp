#include <utility>
#include <iostream>
using namespace std;

int n;

int main() {
	int rank;
	cin >> n;
	if (n < 2 || n > 50) return 0; //���� ����

	pair<int, int>* arr = new pair<int, int>[n]; //(a,b)�� �޴� �迭 ����
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < n; i++) { //�� ������ �˰��� ���1�� �����ϰ� ���2�� ������ �������
		rank = 1; //���1�� ��ȯ�ɶ� ���� ��ũ ����
		for (int j = 0; j < n; j++) {
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) rank++; //������ �Ǹ� ����
		}
		cout << rank << ' ';
	}
	cout << '\n';

	return 0;
}