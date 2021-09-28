#include <iostream>
#include <deque>

using namespace std;

int n, m;

int solution(void) {
	int cnt = 0;
	deque<int> dq;

	//dq에 1부터 n까지 
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	//이제 m번 target을 찾기 위한 연산
	for (int i = 0; i < m; i++) {
		int target, idx;
		cin >> target;
		
		//target의 위치를 찾음
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == target) {
				idx = i;
				break;
			}
		}
		//2번할지 3번 할지 결정
		if (idx < dq.size() - idx) {
			while (true) {
				if (target == dq.front()) {
					dq.pop_front();
					break;
				}
				//2번 연산 수행
				cnt++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			while (true) {
				if (target == dq.front()) {
					dq.pop_front();
					break;
				}
				//3번 연산 수행
				cnt++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	return cnt;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int ret = solution();
	cout << ret << '\n';
	return 0;
}
