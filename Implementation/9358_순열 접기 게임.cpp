#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int solution(int n, vector<int>& arr) {
	int answer = 0;
	deque<int> dq;
	deque<int> tmp;

	for (int& a : arr)
		dq.push_back(a);

	while (1) {
		// 2개가 남았다면
		if (dq.size() == 2) {
			answer = dq[0] > dq[1] ? 1 : 0;
			break;
		}


		while (!dq.empty()) {
			tmp.push_back(dq.front() + dq.back());
			dq.pop_front();

			// 뒤에 것
			if (!dq.empty())
				dq.pop_back();
		}

		while (!tmp.empty()) {
			dq.push_back(tmp.front());
			tmp.pop_front();
		}
	}

	return answer;
}

int main(void) {
	int T;

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		vector<int> arr;

		cin >> n;
		arr = vector<int>(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		int ret = solution(n, arr);
		if (ret == 1)
			cout << "Case #" << t << ": " << "Alice" << '\n';
		else
			cout << "Case #" << t << ": " << "Bob" << '\n';
	}

	return 0;
}
