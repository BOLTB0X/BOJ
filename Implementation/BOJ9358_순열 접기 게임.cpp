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
		deque<int> temp_dq; //임시 dq
		while (true) {
			if (dq.size() == 2) break; //dq길이 체크
			while (!dq.empty())	{ //접기 시작
				temp_dq.push_back(dq.front() + dq.back()); //값들을 임시 dq에 저장
				dq.pop_front();
				if (!dq.empty()) 
					dq.pop_back();
			}
			while (!temp_dq.empty()){ //임시 dq에 있는 값들을 원래 dp로 옮김
				dq.push_back(temp_dq.front());
				temp_dq.pop_front();
			}
		}
		printf("Case #%d: %s\n", i, dq[0] > dq[1] ? "Alice" : "Bob");
	}
	return 0;
}