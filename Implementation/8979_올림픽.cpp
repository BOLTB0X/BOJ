#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Medal{
	int idx, gold, silver, bronze;
};

int idx;

int compare(Medal& a, Medal& b) {
	if (a.gold == b.gold) {
		if (a.silver == b.silver) {
			if (a.bronze == b.bronze)
				// 동일 랭크에 대해 K번째 나라가 제일 먼저 오도록
				return a.idx == idx;
			return a.bronze > b.bronze;
		}
		return a.silver > b.silver;
	}
	return a.gold > b.gold;
}

int solution(int n, int k, Medal* arr) {
	int answer = 0;
	idx = k;
	sort(arr, arr + n, compare);

	for (int i = 0; i <n;++i) {
		if (arr[i].idx == k) {
			answer = i + 1;
			break;
		}
	}

	return answer;
}

int main(void) {
	int n, k;
	Medal arr[1001];

	cin >> n >> k;

	for (int i = 0; i < n; ++i) 
		cin >> arr[i].idx >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
	
	int ret = solution(n, k, arr);
	cout << ret;

	return 0;
}