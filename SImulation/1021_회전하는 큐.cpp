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
	//큐 원소 삽입
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	//시물레이션 시작
	result = 0;
	while(m--) {
		int target;
		cin >> target;
		//해당 위치를 찾음
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == target) {
				idx = i;
				break;
			}
		}
		//idx를 기준 왼쪽으로 돌릴지 오른쪽으로 돌릴지 확인
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