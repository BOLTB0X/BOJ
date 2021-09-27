#include <iostream>
#include <queue>

using namespace std;

int n, m, result;
deque<int> dq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int idx;
	//ť ���� ����
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	//�ù����̼� ����
	result = 0;
	while(m--) {
		int target;
		cin >> target;
		//�ش� ��ġ�� ã��
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == target) {
				idx = i;
				break;
			}
		}
		//idx�� ���� �������� ������ ���������� ������ Ȯ��
		if (idx < dq.size() - idx) {
			while (true) {
				if (dq.front() == target) {
					dq.pop_front();
					break;
				}
				result++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			while (true) {
				if (dq.front() == target) {
					dq.pop_front();
					break;
				}
				result++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	cout << result << '\n';
	return 0;
}