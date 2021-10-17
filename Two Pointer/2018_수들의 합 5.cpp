#include <iostream>

using namespace std;

int solution(int n) {
	//투 포인터 알고리즘
	int cnt = 0;
	int start = 1, end = 2;
	int partial_tot = 1;

	while (start <= n) {
		partial_tot += end;
		if (partial_tot == n) {
			cnt++;
			partial_tot = 0;
			start++;
			end=start;
		}
		else if (partial_tot < n) {
			end++;
		}
		else if (partial_tot > n){
			start++;
			partial_tot = 0;
			end = start;
		}
	}
	return cnt;
}

int main(void) {
	int n, ret;

	cin >> n;
	ret = solution(n);
	
	cout << ret << '\n';
	return 0;
}