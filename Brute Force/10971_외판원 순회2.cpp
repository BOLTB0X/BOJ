#include <iostream>

using namespace std;

int n, result;

//�� Ž�� �Ǿ����� üũ�Լ�
bool check(bool* visited) {
	for (int i = 1; i < n; i++) {
		if (!visited[i])
			return false;
	}
	return true;
}

//���� �켱 Ž��
void DFS(int (*graph)[11], bool* visited, int tot, int depth) {
	//��� ���� Ž���ߴٸ�
	if (check(visited)) {
		//������ ��ġ ����
		if (graph[depth][0] != 0) {
			tot += graph[depth][0];
			//�ּҰ� ������ �Ǹ�
			if (tot < result)
				result = tot;
		}
		return;
	}
	//����� ���� Ž��
	for (int i = 1; i < n; i++) {
		//�׷����� 0�� �ƴϰ� �̹湮�̸�
		if (graph[depth][i] != 0 && !visited[i]) {
			visited[i] = true;
			DFS(graph, visited, tot + graph[depth][i], i);
			visited[i] = false;
		}
	}
}

//�ذ��Լ�
void solution(int(*graph)[11], bool* visited) {
	//�ذ�
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> graph[y][x];
		}
	}
	//��� ����
	result = 987654321;
	//�� ���� Ž������
	DFS(graph, visited, 0, 0);
	cout << result << '\n';
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int graph[11][11];
	bool visited[11] = { false, };

	//�ַ�ǽ���
	solution(graph, visited);
	
	return 0;
}