#include <iostream>
#include <queue>

using namespace std;

void solution(int n, int* arr) {
	priority_queue<int> pq;

	for (int i = 0; i < n; ++i)
		pq.push(-arr[i]);

	while (!pq.empty()) {
		cout << -pq.top() << '\n';
		pq.pop();
	}

	return;
}

int main(void) {
	int n;
	int* arr;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	solution(n, arr);
	return 0;
}