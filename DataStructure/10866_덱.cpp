#include <iostream>
#include <queue>
#include <string>

using namespace std;

void solution(void) {
	int T;
	cin >> T;
	deque<int> dq;

	while (T--) {
		string cmm;
		cin >> cmm;

		if (cmm == "push_back") {
			int value;
			cin >> value;
			dq.push_back(value);
		}

		else if (cmm == "push_front") {
			int value;
			cin >> value;
			dq.push_front(value);
		}
		
		else if (cmm == "pop_front") {
			if (dq.empty())
				cout << -1 << '\n';

			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		
		else if (cmm == "pop_back") {
			if (dq.empty())
				cout << -1 << '\n';

			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		
		else if (cmm == "front") {
			if (dq.empty()) 
				cout << -1 << '\n';
			
			else 
				cout << dq.front() << '\n';
			
		}
		
		else if (cmm == "back") {
			if (dq.empty()) 
				cout << -1 << '\n';
			
			else 
				cout << dq.back() << '\n';
		}

		else if (cmm == "size") 
			cout << dq.size() << '\n';
		
		else if (cmm == "empty") 
			cout << dq.empty() << '\n';
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}