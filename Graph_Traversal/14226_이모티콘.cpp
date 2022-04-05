#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	int display_c, clipboard_c, sec_c;
} Inf;

// 너비우선탐색
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
		
		// 탈출 조건
		if (display== s) 
			return sec;
		
		// 범위 내
		if (display > 0 && display < 1001) {
			// 화면에 있는 이모티콘 복사
			if (visited[display][display] == 0) {
				visited[display][display] = 1;
				que.push({ display, display, sec + 1 });
			}

			// 클립보드에 잇는 모든 이모티콘 화면에 복사
			if (clipboard > 0 && display + clipboard < 1001) {
				if (visited[display + clipboard][clipboard] == 0) {
					visited[display + clipboard][clipboard] = 1;
					que.push({ display + clipboard, clipboard, sec + 1 });
				}
			}

			// 화면에 있는 이모티콘 중 하나를 삭제
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
	//입력
	cin >> s;

	int ret = solution(s);
	cout << ret;
	return 0;
}