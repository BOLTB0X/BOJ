#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n,T;
deque<int> dq[1001];

void rotate_gear(queue<pair<int, int>> q) {
	while (!q.empty()) {
		//큐의 정보 
		int cur_idx = q.front().first;
		int turn_dir = q.front().second;
		q.pop();

		//만약 방향이 시계방향이면
		//가장 하단에 있는게 상단으로
		if (turn_dir == 1) {
			int tmp = dq[cur_idx].back();
			dq[cur_idx].pop_back();
			dq[cur_idx].push_front(tmp);
		}//만약 방향이 빈시계방향이면
		//가장 상단에 있는게 하단으로
		else if (turn_dir == -1) {
			int tmp = dq[cur_idx].front();
			dq[cur_idx].pop_front();
			dq[cur_idx].push_back(tmp);
		}
	}
	return;
}

void turn_check(queue<pair<int, int>> q, int gear_idx, int dir) {
	int idx = gear_idx;
	int tmp_dir = dir;
	q.push({ idx,tmp_dir });
	
	//먼저 오른쪽에 있는 톱니바퀴의 회전관련 정보확인
	while (true) {
		if (idx == n)
			break;
		idx++;
		tmp_dir *= -1;
		if (dq[idx - 1][2] != dq[idx][6])
			q.push({ idx,tmp_dir });
		else
			break;
	}
	idx = gear_idx;
	tmp_dir = dir;
	// 이와 반대로 왼쪽 
	while (true) {
		if (idx == 1)
			break;
		idx--;
		tmp_dir *= -1;
		if (dq[idx + 1][6] != dq[idx][2])
			q.push({ idx,tmp_dir });
		else
			break;
	}
	rotate_gear(q);
	return;
}

//12시방향이 S극인 톱니바퀴의 개수
int get_gears_count() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dq[i][0] == 1)
			cnt++;
	}
	return cnt;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//입력
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string tmp_gear;
		cin >> tmp_gear;
		//톱니바퀴 8방향 정보 저장
		for (int j = 0; j < tmp_gear.length(); j++) {
			dq[i].push_back(tmp_gear[j] - '0');
		}
	}
	//회전정보 큐
	queue<pair<int,int>> q;
	cin >> T;
	while (T!=0) {
		int gear_idx, dir;
		cin >> gear_idx >> dir;
		//회전 전 사전정보확인
		turn_check(q,gear_idx,dir);
		while (!q.empty()) 
			q.pop();
		T--;
	}
	int ret = get_gears_count();
	cout << ret << "\n";
	return 0;
}
