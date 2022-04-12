#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

int solution(int n, pair<int, int>* arr) {
	int answer = 0;

	sort(arr, arr + n, compare); // ���� ������ �������� ����
	int max_score = arr[0].second;

	// �׸���
	for (int i = 0; i < n; ++i) {
		// �۴� -> ����� ����
		if (arr[i].second <= max_score) {
			answer++;
			max_score = arr[i].second;
		}
	}

	return answer;
}

int main(void) {
	int T;

	cin >> T;
	while (T--) {
		int n;
		pair<int, int> arr[100000];

		cin >> n;
		for (int i = 0; i < n; ++i) 
			cin >> arr[i].first >> arr[i].second;
		
		int ret = solution(n, arr);
		cout << ret << '\n';
	}
	return 0;
}