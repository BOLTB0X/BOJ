#include <iostream>
#include <queue>

using namespace std;

void solution(void) {
	int T;
	queue <int> q;
	
	int value;
	string cmm;
	
	cin >> T;
	for (int i=0; i<T;++i) {
		cin >> cmm;

		if (cmm == "push") {
			cin >> value;
			q.push(value);
		}

		else if (cmm == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}

		else if (cmm == "size") 
			cout << q.size() << '\n';
		
		else if (cmm == "empty") {
			cout << q.empty() << '\n';
		}

		else if (cmm == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else 
				cout << q.front() << '\n';
			
		}
		
		else if (cmm == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else 
				cout << q.back() << '\n';
			
		}
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