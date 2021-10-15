#include <iostream>
#include <vector>

using namespace std;

int result = -1;
vector<int> per;

//�ִ밪 ��
int max(int a, int b) {
	return a > b ? a : b;
}

//���� ��ȯ
int abs(int a) {
	if (a < 0)
		return -a;
	return a;
}

//���̰� ��ȯ
int get_target(vector<int>& per, int n) {
	int tot = 0;
	for (int i = 0; i < n-1; i++) {
		tot += abs(per[i] - per[i + 1]);
	}
	return tot;
}

//���� �켱 Ž��
void DFS(int* arr, bool* visited, int n, int depth) {
	if (depth == n) {
		result = max(result, get_target(per,n));
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		per.push_back(arr[i]);
		visited[i] = true;
		DFS(arr, visited, n, depth + 1);
		per.pop_back();
		visited[i] = false;
	}
}

//�ذ�
void solution(void) {
	int n;
	cin >> n;

	//�޸� ����
	int* arr = new int[n];
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		visited[i] = false;
	}

	DFS(arr, visited, n, 0);
	cout << result << '\n';

	//�޸� ����
	delete[] arr;
	delete[] visited;
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