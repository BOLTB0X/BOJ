#include <iostream>
#include <cstring>
#include <algorithm>
#define LL long long 

using namespace std;

LL arr[100000];

LL solution(int n) {
	LL answer = 0;
	sort(arr, arr + n);
	int idx = 0, cnt = 1, max_cnt = 0;

	for (int i = 0; i < n - 1; ++i) {
		if (arr[i] == arr[i + 1]) {
			cnt++;
			if (cnt > max_cnt) {
				max_cnt = cnt;
				idx = i;
			}
		}
		else 
			cnt = 1;
	}

	answer = arr[idx];
	return answer;
}

int main(void) {
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	LL ret = solution(n);
	cout << ret;
	return 0;
}