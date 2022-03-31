#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int idx, dir;
} Pair;

deque<int> dq[1001]; // 톱니바퀴
Pair cmd[1000];

void prepare_Rotate(queue<Pair>& que, int t, int gidx, int gdir) {
	int idx = gidx;
	int dir = gdir;
	que.push({ idx, dir }); // 회전할 번호와 방향 삽입

	// 먼저 시계방향
	// ->
	while (1) {
		if (idx == t)
			break;

		idx++;
		dir *= -1;

		// ->
		if (dq[idx - 1][2] != dq[idx][6])
			que.push({ idx, dir });
		else
			break;
	}

	idx = gidx;
	dir = gdir;

	// 먼저 반시계방향
	// <-
	while (1) {
		if (idx == 1)
			break;

		idx--;
		dir *= -1;

		// ->
		if (dq[idx][2] != dq[idx + 1][6])
			que.push({ idx, dir });
		else
			break;
	}
	return;
}

void Rotate_gear(queue<Pair>& que, int t) {
	while (!que.empty()) {
		// 회전할 정보
		int cidx = que.front().idx;
		int cdir = que.front().dir;
		que.pop();

		// 시계방향 회전
		// ->, 상단 -> 하단
		if (cdir == 1) {
			int tmp = dq[cidx].back();
			dq[cidx].pop_back();
			dq[cidx].push_front(tmp);
		}
		
		// 반시계방향 회전
		// <-, 상단 <- 하단
		else if (cdir == -1) {
			int tmp = dq[cidx].front();
			dq[cidx].pop_front();
			dq[cidx].push_back(tmp);
		}
	}

	return;
}

// 카운트
int get_Count_gear(int t) {
	int cnt = 0;
	for (int i = 1; i <= t; ++i) {
		// 12시방향
		if (dq[i][0] == 1)
			cnt++;
	}

	return cnt;
}

int solution(int t, int k) {
	int answer = 0;
	queue<Pair> que;

	// 명령조건에 따라 회전
	for (int i = 0; i < k; ++i) {
		prepare_Rotate(que, t, cmd[i].idx, cmd[i].dir); // 배열 정보
		Rotate_gear(que, t);

		while (!que.empty())
			que.pop();
	}

	answer = get_Count_gear(t);
	return answer;
}

int main(void) {
	int T, K;
	string tmp;

	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> tmp;
		for (int j = 0; j < 8; ++j)
			dq[i].push_back(tmp[j] - '0');
	}

	cin >> K;
	for (int i = 0; i < K; ++i)
		cin >> cmd[i].idx >> cmd[i].dir;

	int ret = solution(T, K);
	cout << ret;
	return 0;
}
