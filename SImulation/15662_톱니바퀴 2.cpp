#include <iostream>
#include <queue>
#include <string>

using namespace std;

int T, k;
string gears[1001];
pair<int, int> cmd[1001];

deque<int> dq[1001];

void input(void) {
	string cmm;

	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> cmm;
		for (int j = 0; j < 8; ++j)
			dq[i].push_back(cmm[j] - '0');
	}

	cin >> k;
	for (int i = 1; i <= k; ++i) {
		int number, dir;
		cin >> number >> dir;
		cmd[i].first = number;
		cmd[i].second = dir;
	}

	return;
}

void rotate_gear(queue<pair<int, int>> que) {
	while (!que.empty()) {
		//ť�� ���� 
		int cur_idx = que.front().first;
		int turn_dir = que.front().second;
		que.pop();

		//���� ������ �ð�����̸�
		//���� �ϴܿ� �ִ°� �������
		if (turn_dir == 1) {
			int tmp = dq[cur_idx].back();
			dq[cur_idx].pop_back();
			dq[cur_idx].push_front(tmp);
		}
		
		//���� ������ ��ð�����̸�
		//���� ��ܿ� �ִ°� �ϴ�����
		else if (turn_dir == -1) {
			int tmp = dq[cur_idx].front();
			dq[cur_idx].pop_front();
			dq[cur_idx].push_back(tmp);
		}
	}
	return;
}

void before_Rotate_Check(queue<pair<int, int>> que, int gear_idx, int dir) {
	int idx = gear_idx;
	int tmp_dir = dir;
	que.push({ idx, tmp_dir });

	while (1) {
		if (idx == T)
			break;
		idx++;
		tmp_dir *= -1;

		if (dq[idx - 1][2] != dq[idx][6])
			que.push({ idx, tmp_dir });
		else
			break;
	}
	idx = gear_idx;
	tmp_dir = dir;

	while (1) {
		if (idx == 1)
			break;
		idx--;
		tmp_dir *= -1;

		if (dq[idx + 1][6] != dq[idx][2])
			que.push({ idx, tmp_dir });
		else
			break;
	}

	//��� ������ ������� ȸ��
	rotate_gear(que);
	return;
}

//12�ù����� S���� ��Ϲ����� ����
int get_gears_count(void) {
	int cnt = 0;
	for (int i = 1; i <= T; i++) {
		if (dq[i][0] == 1)
			cnt++;
	}
	return cnt;
}

void solution(void) {
	queue<pair<int, int>> que;
	//�ù� ����
	for (int i = 1; i <= k; ++i) {
		before_Rotate_Check(que, cmd[i].first, cmd[i].second);
		while (!que.empty()) {
			que.pop();
		}
	}

	int ret = get_gears_count();
	cout << ret << "\n";
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	
	input();
	solution();

	return 0;
}