#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> topo;
bool visited[32001] = { false, };

//���� �켱 Ž��
void DFS(vector<vector<int>>& graph, int depth) {
	visited[depth] = true;
	for (int i = 0; i < graph[depth].size(); i++) {
		int next = graph[depth][i];

		if (!visited[next])
			DFS(graph, next);
	}	
	topo.push(depth);
}

void solution(int n, int m, vector<vector<int>>& graph) {
	//�������� �̿�
	//�̹湮�� ���
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) 
			DFS(graph, i);
	}

	//topo ���
	while (!topo.empty()) {
		cout << topo.top() << ' ';
		topo.pop();
	}
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	//���� �ʱ�ȭ
	vector<vector<int>> graph(n + 1);
	for (int i = 1; i <= m; i++) {
		int front, back;
		cin >> front >> back;
		graph[front].push_back(back);
	}
	solution(n,m,graph);
	return 0;
}