#include <iostream>
#include <queue>

using namespace std;

void solution(void) {
	int N, K;
	queue<int> q;
	
	//입력
	cin >> N >> K;

	//1부터 N까지 q에 삽입
	for (int i = 1; i <= N; ++i)
		q.push(i);
	
	//요세푸스 시작
	//해법은 k-1번 push,pop하고 상단 출력
	//반복
	
	cout << "<";
	while (!q.empty()) {
		//원소가 하나 남았다면
		if (q.size() == 1) {
			cout << q.front() << ">";
			q.pop();
			break;
		}
		
		//m-1 pop,push
		for (int i = 1; i < K; ++i) {
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
