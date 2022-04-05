#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	int display_c, clipboard_c, sec_c;
} Inf;

// �ʺ�켱Ž��
int BFS(int s) {
	queue<Inf> que;
	vector<vector<int>> visited(1001, vector<int>(1001, 0));
	que.push({ 1,0,0 });
	visited[1][0] = 1;

	while (!que.empty()) {
		int display = que.front().display_c;
		int clipboard = que.front().clipboard_c;
		int sec = que.front().sec_c;
		que.pop();
		
		// Ż�� ����
		if (display== s) 
			return sec;
		
		// ���� ��
		if (display > 0 && display < 1001) {
			// ȭ�鿡 �ִ� �̸�Ƽ�� ����
			if (visited[display][display] == 0) {
				visited[display][display] = 1;
				que.push({ display, display, sec + 1 });
			}

			// Ŭ�����忡 �մ� ��� �̸�Ƽ�� ȭ�鿡 ����
			if (clipboard > 0 && display + clipboard < 1001) {
				if (visited[display + clipboard][clipboard] == 0) {
					visited[display + clipboard][clipboard] = 1;
					que.push({ display + clipboard, clipboard, sec + 1 });
				}
			}

			// ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� ����
			if (visited[display - 1][clipboard] == 0) {
				visited[display - 1][clipboard] = 1;
				que.push({ display - 1, clipboard, sec + 1 });
			}
		}
	}
	return 0;
}

int solution(int s) {
	int answer = 0;

	answer = BFS(s);
	return answer;
}

int main(void) {
	int s;
	//�Է�
	cin >> s;

	int ret = solution(s);
	cout << ret;
	return 0;
}