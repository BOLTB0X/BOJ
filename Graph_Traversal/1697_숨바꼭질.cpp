#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//�湮����Ʈ ����
bool visited[100001] = { false, };

//�ʺ�켱Ž��
void BFS(int n, int k) {
	//ť ����
	queue<pair<int, int>> q;
	//��ġ �� �ɸ� �ð� ����
	q.push({ n,0 });
	//�湮ó��
	visited[n] = true;

	//ť�� �����������
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		//Ż�� ����
		if (cur.first == k) {
			cout << cur.second << '\n';
			return;
		}

		//�� ���Ǻ� �б�� ����
		//2���� ���
		if (cur.first * 2 <= 100001 && !visited[cur.first * 2]) {
			visited[cur.first * 2] = true;
			q.push({ cur.first * 2, cur.second + 1 });
		}
		
		//+1�� ���
		if (cur.first + 1 <= 100001 && !visited[cur.first + 1]) {
			visited[cur.first + 1] = true;
			q.push({ cur.first + 1, cur.second + 1 });
		}
		
		//-1�� ���
		if (cur.first - 1 >= 0 && !visited[cur.first - 1]) {
			visited[cur.first - 1] = true;
			q.push({ cur.first - 1, cur.second + 1 });
		}
	}
	
	return;
}

void simulation(void) {
	int n, k;
	cin >> n >> k;

	BFS(n, k);
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	simulation();
	return 0;
}