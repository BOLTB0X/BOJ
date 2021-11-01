#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> com;
set<vector<int>> ans_com;

//���̿켱Ž��
void DFS(vector<int>& arr, int n, int m, int cur, int depth) {
	//Ż������
	if (com.size() == m) {
		vector<int> tmp;
		for (int i = 0; i < com.size(); ++i)
			tmp.push_back(com[i]);
		//���� ���͸� set�� ����
		ans_com.insert(tmp);
		return;
	}

	for (int i = cur; i < arr.size(); ++i) {
		com.push_back(arr[i]);
		DFS(arr, n, m, i, depth + 1);
		com.pop_back();
	}
	return;
}

void solution(void) {
	int n, m;

	//�Է�
	cin >> n >> m;

	//���� ������ ����
	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	//��������
	sort(arr.begin(), arr.end());

	//Ž�� ����
	DFS(arr, n, m, 0, 0);

	//���
	for (auto a : ans_com) {
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << ' ';
		cout << '\n';
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