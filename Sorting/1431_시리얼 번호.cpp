#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& A, const string& B) {
	// ũ�� ��
	int A_size = A.length(), B_size = B.length();
	if (A_size != B_size) 
		return A_size < B_size;

	// �� ���ϰ� ��
	int A_sum = 0, B_sum = 0;
	for (int i = 0; i < A_size; i++) {
		if ('0' <= A[i] && A[i] <= '9')    
			A_sum += A[i] - '0';
		if ('0' <= B[i] && B[i] <= '9')    
			B_sum += B[i] - '0';
	}

	if (A_sum != B_sum) 
		return A_sum < B_sum;

	// ������ ��
	return A < B;
}

void solution(void) {
	int n;
	cin >> n;

	//���� �ʱ�ȭ
	//2���� ����
	vector<string> arr(n);

	//�Է�
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	
	//����
	sort(arr.begin(), arr.end(), compare);

	//���
	for (int i = 0; i < n; ++i)
		cout << arr[i] << '\n';

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