#include <iostream>
#include <algorithm>
using namespace std;

//투 포인터 알고리즘
int two_pointer(int* arr, int size, long long target) {
	int start = 0, end = size - 1;
	//부분합
	int partial_tot = 0;
	//횟수
	int cnt = 0;
	
	//투포인터 알고리즘을 위한 오름차순 정렬
	sort(arr, arr + size);

	//반복문 시작
	while (start < end) {
		partial_tot = arr[start] + arr[end];

		//부분합이 타겟과 같다면
		if (partial_tot == target) {
			cnt++;
			start++;
			end--;
		}

		//만약 부분합이 타겟보다 작다면
		else if (partial_tot < target) 
			start++;
	
		//만약 부분합이 타겟보다 크다면
		else if (partial_tot > target) 
			end--;
	}
	return cnt;
}

//해결
void solution(void) {
	int n;
	long long x;
	
	//입력
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//타겟
	cin >> x;
	int ret = two_pointer(arr, n, x);
	cout << ret << '\n';
	delete[] arr;
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//문제해결
	solution();

	return 0;
}
