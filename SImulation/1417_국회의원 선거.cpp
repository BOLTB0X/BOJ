#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int* arr) {
	int answer = 0;
	vector<int> votes;
	if (n == 1)
		return 0;

	int dasom = arr[0];
	for (int i = 1; i < n; ++i)
		votes.push_back(arr[i]);

	while (1) {
		int max_value = 0;
		int idx = 0;

		// ���� ū �� ã��
		for (int i = 0; i < n - 1; ++i) {
			if (max_value < votes[i]) {
				max_value = votes[i];
				idx = i;
			}
		}

		// �ټ��� ���ǥ���̸�
		if (dasom > max_value) 
			break;

		// �ż�
		dasom++;
		votes[idx]--;
		answer++;
	}

	return answer;
}

int main(void) {
	int n;
	int* arr;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret = solution(n, arr);
	cout << ret;
	delete[] arr;
	return 0;
}