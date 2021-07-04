#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int n, k; //n�� ������ ��ġ , k�� ������ġ== Ÿ��
bool visited[MAX];
queue<pair<int,int>> que;
int cnt = 0,answer=0;

int BFS(int n, int k) {
	que.push(make_pair(n ,0));
	visited[n] = true; //�湮ó��
	while (!que.empty()) {
		int x = que.front().first;
		int sec = que.front().second;
		que.pop();
		visited[x] = true;

		if (answer && x==k && sec==answer) {
			cnt ++;
		}//������ġ�� ���ٸ�

		if (!answer && x == k) {
			answer = sec;
			cnt ++;
		}//������ġ�� ���ٸ�

		if (x + 1 < MAX && x + 1 >= 0 && !visited[x + 1]) { //������ �ش��ϰ� �� �湮�̸�
			que.push({ x + 1,sec + 1 });
		}

		if (x - 1 < MAX && x - 1 >= 0 && !visited[x - 1]) { //������ �ش��ϰ� �� �湮�̸�
			que.push({ x - 1,sec + 1 });
		}

		if (x * 2 < MAX && x * 2 >= 0 && !visited[x * 2]) { //������ �ش��ϰ� �� �湮�̸�
			que.push({ x * 2,sec + 1 });
		}
	}
	return answer;
}

int main(void) {
	cin >> n >> k;

	cout << BFS(n,k) << '\n';
	cout << cnt << '\n';
	return 0;
}