#include <iostream>
#include <queue>

using namespace std;

void solution(void) {
	int n;
	priority_queue<int> pq;

	//입력
	cin >> n;

	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;

		if (value == 0) {
			if (pq.empty()) 
				cout << "0\n";
			else {
				int p = pq.top();
				pq.pop();
				cout << p << '\n';
			}
		}
		else {
			pq.push(value);
		}
	}
	
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
