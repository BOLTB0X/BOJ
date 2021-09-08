#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n,T;
deque<int> dq[1001];

void rotate_gear(queue<pair<int, int>> q) {
	while (!q.empty()) {
		//ť�� ���� 
		int cur_idx = q.front().first;
		int turn_dir = q.front().second;
		q.pop();

		//���� ������ �ð�����̸�
		//���� �ϴܿ� �ִ°� �������
		if (turn_dir == 1) {
			int tmp = dq[cur_idx].back();
			dq[cur_idx].pop_back();
			dq[cur_idx].push_front(tmp);
		}//���� ������ ��ð�����̸�
		//���� ��ܿ� �ִ°� �ϴ�����
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
	
	//���� �����ʿ� �ִ� ��Ϲ����� ȸ������ ����Ȯ��
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
	// �̿� �ݴ�� ���� 
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

//12�ù����� S���� ��Ϲ����� ����
int get_gears_count() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dq[i][0] == 1)
			cnt++;
	}
	return cnt;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//�Է�
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string tmp_gear;
		cin >> tmp_gear;
		//��Ϲ��� 8���� ���� ����
		for (int j = 0; j < tmp_gear.length(); j++) {
			dq[i].push_back(tmp_gear[j] - '0');
		}
	}
	//ȸ������ ť
	queue<pair<int,int>> q;
	cin >> T;
	while (T!=0) {
		int gear_idx, dir;
		cin >> gear_idx >> dir;
		//ȸ�� �� ��������Ȯ��
		turn_check(q,gear_idx,dir);
		while (!q.empty()) 
			q.pop();
		T--;
	}
	int ret = get_gears_count();
	cout << ret << "\n";
	return 0;
}
