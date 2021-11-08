#include <iostream>
#include <queue>

using namespace std;

//�湮����Ʈ
bool visited[100001] = { false, };

void simulation(void) {
	int n, k;
	cin >> n >> k;

	deque<pair<int, int>> dq;
	dq.push_back({ n,0 });
	visited[n] = true;

	while (!dq.empty()) {
		//���� ��ġ
		int cur_l = dq.front().first;
		//���� �ð�
		int cur_t = dq.front().second;
		dq.pop_front();

		//��ǥ ��ġ�� �����ϸ�
		if (cur_l == k) {
			cout << cur_t << '\n';
			break;
		}

		//3���� ����� ��
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
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	simulation();
	return 0;
}