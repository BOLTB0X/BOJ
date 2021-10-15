#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result = -1;

//최댓값 비교
int max(int a, int b) {
	return a > b ? a : b;
}

//차이값 반환
int get_difference_value(vector<int>& v, int n) {
	int tot = 0;
	for (int i = 0; i < n - 1; i++) {
		tot += abs(v[i] - v[i + 1]);
	}
	return tot;
}

void solution(void) {
	int n;
	cin >> n;
	vector<int> per(n);

	for (int i = 0; i < n; ++i)
		cin >> per[i];
	
	//오름차순 정렬
	sort(per.begin(), per.end());

	//다음 순열 알고리즘 이용
	do {
		result = max(result, get_difference_value(per, n));
	} while (next_permutation(per.begin(), per.end()));

	cout << result << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
