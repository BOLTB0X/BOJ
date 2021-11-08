#include <iostream>
#include <queue>

using namespace std;

//방문리스트
bool visited[100001] = { false, };

void simulation(void) {
	int n, k;
	cin >> n >> k;

	deque<pair<int, int>> dq;
	dq.push_back({ n,0 });
	visited[n] = true;

	while (!dq.empty()) {
		//현재 위치
		int cur_l = dq.front().first;
		//현재 시간
		int cur_t = dq.front().second;
		dq.pop_front();

		//목표 위치에 도달하면
		if (cur_l == k) {
			cout << cur_t << '\n';
			break;
		}

		//3가지 경우의 수
		if (cur_l * 2 < 100001 && !visited[cur_l * 2]) {
			dq.push_front({ (cur_l * 2),cur_t });
			visited[cur_l * 2] = true;
		}
		if (cur_l + 1 < 100001 && !visited[cur_l + 1]) {
			dq.push_back({ (cur_l + 1),cur_t + 1 });
			visited[cur_l + 1] = true;
		}
		if (cur_l - 1 >= 0 && !visited[cur_l - 1]) {
			dq.push_back({ (cur_l - 1),cur_t + 1 });
			visited[cur_l - 1] = true;
		}
	}
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