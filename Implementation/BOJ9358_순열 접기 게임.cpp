#include <iostream>
#include <deque>
using namespace std;

int main() {
	int t,value;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		deque<int> dq;
		for (int j = 0; j < n; j++) {
			cin >> value;
			dq.push_back(value);
		}
		deque<int> temp_dq; //�ӽ� dq
		while (true) {
			if (dq.size() == 2) break; //dq���� üũ
			while (!dq.empty())	{ //���� ����
				temp_dq.push_back(dq.front() + dq.back()); //������ �ӽ� dq�� ����
				dq.pop_front();
				if (!dq.empty()) 
					dq.pop_back();
			}
			while (!temp_dq.empty()){ //�ӽ� dq�� �ִ� ������ ���� dp�� �ű�
				dq.push_back(temp_dq.front());
				temp_dq.pop_front();
			}
		}
		printf("Case #%d: %s\n", i, dq[0] > dq[1] ? "Alice" : "Bob");
	}
	return 0;
}