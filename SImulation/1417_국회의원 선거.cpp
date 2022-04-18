#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int& a, int& b) {
	return a > b;
}

int solution(int n, int* arr) {
	int answer = 0;
	if (n == 1)
		return answer;
	vector<int> votes;
	int dasom = arr[0];

	for (int i = 1; i < n; ++i)
		votes.push_back(arr[i]);

	while (1) {
		sort(votes.begin(), votes.end(), compare); // 오름차순
		
		if (dasom > votes[0])
			break;
		dasom++;
		votes[0]--;
		answer++;
	}
	return answer;
}

int main(void) {
	int n;
	int* arr;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret = solution(n, arr);
	cout << ret;
	delete[] arr;
	return 0;
}
