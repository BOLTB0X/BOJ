#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

// 각 원소의 차이값 반환
int get_diff(vector<int>& per) {
	int tot = 0;
	int size = per.size();

	for (int i = 0; i < size - 1; ++i)
		tot += abs(per[i] - per[i + 1]);
	return tot;
}

int solution(int n, vector<int>& per) {
	int answer = -1;
	// 먼저 오름차순 정렬
	sort(per.begin(), per.end());

	do {
		answer = Max(answer, get_diff(per));
	} while (next_permutation(per.begin(), per.end()));

	return answer;
}

int main(void) {
	int n;
	vector<int> per;

	cin >> n;
	per.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> per[i];

	int ret = solution(n, per);
	cout << ret;
	return 0;
}
