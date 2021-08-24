#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
int visited[101] = { 0, };
int min_value = 0x7fffffff;
int result;

int min(int a, int b) {
	return a < b ? a : b;
}

//�湮 �ʱ�ȭ
void init() {
	//�� ��� �� �Ÿ����� �ʱ�ȭ
	for (int i = 1; i <= n; i++) 
		visited[i] = 0;

}

void BFS(int start) {
	queue<int> q;
	visited[start] = 1;
	q.push(start);

	//ť�� ��������
	//������ �� �湮�Ÿ� ����
	while (!q.empty()) {
		start = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			//��ŸƮ ���� ���� �ְ� �湮������ ���ٸ�
			if (map[start][i] == 1 && visited[i] == 0) {
				visited[i] = visited[start] + 1;
				//���� ������� ť�� ����
				q.push(i);
			}
		}
	}
}

//�ּ� �湮���̸� ���� ���� ã��
void find_min_vertex(int start) {
	int tmp_tot = 0;
	//�� visited �� ��ŸƮ���� ������ �ɸ��� �����
	for (int j = 1; j <= n; j++) {
		// �ڱ� �ڽ��� ����
		if (start == j) continue;
		//÷ ������ 1�� �����Ƿ�
		tmp_tot += (visited[j] - 1);
	}
	if (tmp_tot < min_value) {
		min_value = tmp_tot;
		result = start;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		//2�� ��Ŀ� üũ
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	for (int start = 1; start <= n; start++) {
		init();
		BFS(start);
		find_min_vertex(start);
	}

	cout << result << '\n';
	return 0;
}