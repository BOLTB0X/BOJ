#include <iostream>
#include <algorithm>

using namespace std;

int k_idx;

struct Country {
	int idx, gold, silver, bronze;

	bool operator < (const Country& c) const {
		if (gold == c.gold) {
			if (silver == c.silver) {
				if (bronze == c.bronze)
					return idx == k_idx;
				return bronze > c.bronze;
			}
			return silver > c.silver;
		}
		return gold > c.gold;
	}
};

int solution(int n, int k, Country* arr) {
	int answer = 0;

	k_idx = k;
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		if (arr[i].idx == k) {
			answer = i + 1;
			break;
		}
	}
	return answer;
}

int main(void) {
	int n, k;

	Country arr[1001];

	cin >> n >> k;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i].idx >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
	
	int ret = solution(n, k, arr);
	cout << ret;

	return 0;
}
