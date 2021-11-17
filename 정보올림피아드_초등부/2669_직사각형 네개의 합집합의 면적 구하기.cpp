#include <iostream>

using namespace std;

int graph[101][101] = { 0, };

void solution(void) {
	for (int i = 0; i < 4; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		//�ش� �׷��� 1 ó��
		for (int x = x1; x < x2; ++x) 
			for (int y = y1; y < y2; ++y) 
				graph[x][y] = 1;
	}
	
	//�� ��
	int tot = 0;
	for (int x = 0; x < 101; ++x) {
		for (int y = 0; y < 101; ++y) {
			if (graph[x][y] == 1)
				tot++;
		}
	}

	//���
	cout << tot << '\n';
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