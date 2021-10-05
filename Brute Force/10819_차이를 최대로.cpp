#include <iostream>
#include <vector>

using namespace std;

int n, result;
vector<int> per;

//�ִ�
int max(int a, int b) {
	return a > b ? a : b;
}

//����
int abs(int a) {
	return a < 0 ? -a : a;
}

//�ִ밪 ã��
void get_max_value(int* arr, bool* visited) {
	int tot = 0;
	for (int i = 0; i < n - 1; i++) {
		tot += abs(per[i] - per[i + 1]);
	}
	result = max(tot, result);
	return;
}

//���� �켱���� ����Ž��
void DFS(int* arr, bool* visited, int depth) {
	//�Է¹��� n��ŭ �����ߴٸ�
	if (depth == n) {
		get_max_value(arr, visited);
		return;
	}
	//�ߺ������� �ƴϹǷ� ��湮�� ����
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		per.push_back(arr[i]);
		DFS(arr, visited, depth + 1);
		visited[i] = false;
		per.pop_back();
	}
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//�Է�
	cin >> n;
	
	//�����Ҵ�
	int* arr = new int[n];
	bool* visited = new bool[n];
	
	//�ʱ�ȭ
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	//�ʱ�ȭ
	for (int i = 0; i < n; i++) 
		visited[i] = false;
	
	result = -1;
	DFS(arr, visited, 0);
	cout << result << '\n';
	
	delete[] arr;
	delete[] visited;
	
	return 0;
}