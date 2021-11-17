#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//방문리스트 생성
bool visited[100001] = { false, };

//너비우선탐색
void BFS(int n, int k) {
	//큐 선언
	queue<pair<int, int>> q;
	//위치 와 걸린 시간 삽입
	q.push({ n,0 });
	//방문처리
	visited[n] = true;

	//큐가 비어질때까지
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		//탈출 조건
		if (cur.first == k) {
			cout << cur.second << '\n';
			return;
		}

		//각 조건별 분기로 나눔
		//2배인 경우
		if (cur.first * 2 <= 100001 && !visited[cur.first * 2]) {
			visited[cur.first * 2] = true;
			q.push({ cur.first * 2, cur.second + 1 });
		}
		
		//+1인 경우
		if (cur.first + 1 <= 100001 && !visited[cur.first + 1]) {
			visited[cur.first + 1] = true;
			q.push({ cur.first + 1, cur.second + 1 });
		}
		
		//-1인 경우
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
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	simulation();
	return 0;
}