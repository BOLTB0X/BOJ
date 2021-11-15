#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//����ü
struct INF {
	int y, x, cnt;
};

const int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
const int dx[8] = { -2,-1,1,2,2,1,-1,-2 };

//�ʺ�켱Ž��
void BFS(vector<vector<bool>> &visited, int n, int sy, int sx, int ty, int tx) {
	//ť ����
	queue<INF> q;
	q.push({ sy,sx,0 });
	visited[sy][sx] = true;

	while (!q.empty()) {
		INF cur = q.front();
		q.pop();

		//Ż������
		if (cur.y == ty && cur.x == tx) {
			cout << cur.cnt << '\n';
			return;
		}
		
		//�̵����� ���ʷ�
		for (int dir = 0; dir < 8; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//�����ʰ�
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			
			//��湮
			if (visited[ny][nx] == true)
				continue;

			q.push({ ny,nx,cur.cnt + 1 });
			visited[ny][nx] = true;
		}
	}

	return;
}

void solution(void) {
	int T;
	cin >> T;
	
	while (T--) {
		int n;
		int sy, sx, ty, tx;
		vector<vector<bool>> visited;

		cin >> n;
		//���� �ʱ�ȭ
		visited.resize(n, vector<bool>(n, false));
		
		//��ŸƮ, ������
		cin >> sy >> sx;
		cin >> ty >> tx;
		
		//�ʺ�켱Ž�� ȣ��
		BFS(visited, n, sy, sx, ty, tx);;
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