#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int graph[51][51];
bool visited[51][51] = { false, };

// ��,��,��,��,���,����,�»�,����
const int dy[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
const int dx[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };

//���� �켱 Ž��
void DFS(int y, int x) {
	visited[y][x] = true;
	
	//���ʷ� �̵����� Ž��
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		//���� �ʰ�
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;
		//��湮 �� ���� ���
		if (visited[ny][nx] || graph[ny][nx] == 0)
			continue;

		//�湮üũ
		visited[ny][nx] = true;
		DFS(ny, nx);
	}
}

void solution(void) {
	int answer = 0;

	while (true) {
		cin >> m >> n;

		//��������
		if (n == 0 && m == 0) 
			break;
		
		else {
			//���� ���� �ʱ�ȭ
			answer = 0;
			//�׷��� ����
			for (int y = 0; y < n; ++y) {
				for (int x = 0; x < m; ++x) 
					cin >> graph[y][x];
			}
			
			//�׷��� Ž��
			for (int y = 0; y < n; ++y) {
				for (int x = 0; x < m; ++x) {
					if (graph[y][x] == 1 && !visited[y][x]) {
						answer++;
						DFS(y, x);
					}
				}
			}
			
			//���
			cout << answer << '\n';
			
			//�湮����Ʈ �ʱ�ȭ
			memset(visited, false, sizeof(visited));
			answer = 0;
		}
	}
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}