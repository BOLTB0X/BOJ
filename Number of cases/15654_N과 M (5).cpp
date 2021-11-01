#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> per;
vector<bool> visited;

//���̿켱Ž��
void DFS(vector<int>& arr, int n, int m, int depth) {
	//Ż������
	if (per.size() == m) {
		for (int i = 0; i < per.size(); ++i)
			cout << per[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); ++i) {
		if (visited[i])
			continue;
		per.push_back(arr[i]);
		visited[i] = true;
		DFS(arr, n, m, depth + 1);
		per.pop_back();
		visited[i] = false;
	}
	return;
}

void solution(void) {
	int n, m;
	
	//�Է�
	cin >> n >> m;
	
	//���� ������ ����
	vector<int> arr(n);
	visited.resize(n, false);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	//��������
	sort(arr.begin(), arr.end());

	//Ž�� ����
	DFS(arr, n, m, 0);
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