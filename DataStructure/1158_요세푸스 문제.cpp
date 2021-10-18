#include <iostream>
#include <queue>

using namespace std;

void solution(void) {
	// M-1번 pop을 하고 M-1번 push
	int n, m;
	queue<int> q;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) 
		q.push(i);
	
	cout << "<";
	while (!q.empty()) {
		//원소가 하나 남았다면
		if (q.size() == 1) {
			cout << q.front() << ">";
			q.pop();
			break;
		}
		
		//m-1 pop,push
		for (int i = 1; i < m; ++i) {
			q.push(q.front());
			q.pop();
		}
		//상단 출력 후 
		cout << q.front() << ", ";
		q.pop();
	}
	cout << '\n';
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