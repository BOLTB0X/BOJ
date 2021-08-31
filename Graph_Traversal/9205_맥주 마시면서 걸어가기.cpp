#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

//n+�����+������
vector<int> graph[102];
bool visited[102];

//�ʱ�ȭ
void init() {
	for (int i = 0; i < 102; i++) {
		graph[i].clear();
	}
	memset(visited, false, sizeof(visited));
}

//����ź�Ÿ�
int manhattan_distance(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

//���� DFS
void DFS(int cur) {
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (!visited[next])
			DFS(next);
	}
}

//�ùķ��̼�
void solution() {
	//������ �ʱ�ȭ
	init();
	int n;
	vector<pair<int,int>> pos;
	cin >> n;
	//������ ���� �� ���,���� �̹Ƿ�
	for (int j = 0; j < n + 2; j++) {
		int y, x;
		cin >> y >> x;
		pos.push_back(make_pair(y,x)); //��ġ ����
	}
	//���ǿ� �ش��ϴ� �׷�������
	for (int j = 0; j < n + 2; j++) {
		for (int k = j + 1; k < n + 2; k++) {
			//����ź�Ÿ��� 1000���� �۰ų� ������
			if (manhattan_distance(pos[j], pos[k]) <= 20 * 50) {
				graph[j].push_back(k);
				graph[k].push_back(j);
			}
		}
	}
	DFS(0); //����0���� DFS����
	//���ָ� ���������� �湮X;
	if (visited[n + 1])
		cout << "happy" << '\n';
	else
		cout << "sad" << '\n';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin >> test;
	//�׽�Ʈ ����
	for (int t = 0; t < test; t++) {
		solution();
	}
	return 0;
}