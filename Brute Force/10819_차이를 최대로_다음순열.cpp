#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_difference_value(vector<int>& v, int n) {
	int tot = 0;
	for (int i = 0; i < n - 1; i++) {
		tot += abs(v[i] - v[i + 1]);
	}
	return tot;
}

//�Է�
void vector_input(int n, vector<int>& v) {
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		v.push_back(value);
	}
	return;
}

int solution(void) {
	int n, result = 0;
	vector<int> per;
	
	//�Է�
	cin >> n;
	vector_input(n, per);

	//�������� 
	sort(per.begin(), per.end());
	for (int i = 0; i < n - 1; ++i) {
		result += abs(per[i] - per[i + 1]);
	}
	
	//���� ���� �˰���
	int tmp_result;
	do {
		tmp_result = get_difference_value(per, n);
		result = max(result, tmp_result);
	} while (next_permutation(per.begin(), per.end()));

	return result;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//���� ����
	int ret = solution();
	cout << ret << '\n';
	return 0;
}