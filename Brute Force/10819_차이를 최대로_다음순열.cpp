#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_difference_value(vector<int>& v, int n) {
	int tot = 0;
	for (int i = 0; i < n - 1; i++) {
		tot += abs(v[i] - v[i + 1]);
	}
	return tot;
}

//입력
void vector_input(int n, vector<int>& v) {
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		v.push_back(value);
	}
	return;
}

int solution(void) {
	int n, result = 0;
	vector<int> per;
	
	//입력
	cin >> n;
	vector_input(n, per);

	//오름차순 
	sort(per.begin(), per.end());
	for (int i = 0; i < n - 1; ++i) {
		result += abs(per[i] - per[i + 1]);
	}
	
	//다음 순열 알고리즘
	int tmp_result;
	do {
		tmp_result = get_difference_value(per, n);
		result = max(result, tmp_result);
	} while (next_permutation(per.begin(), per.end()));

	return result;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//정답 도출
	int ret = solution();
	cout << ret << '\n';
	return 0;
}