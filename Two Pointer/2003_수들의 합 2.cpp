#include <iostream>
#include <algorithm>

using namespace std;

//투 포인터 알고리즘
//순차적 버전
int two_pointer(int* arr, int size, long long target) {
	int start = 0;
	int end = 0;
	int partial_tot = 0, cnt = 0;

	//투 포인터 알고리즘
	//즉 end가 배열의 길이를 따라잡기 전까지
	while (end <= size) {
		//부분합이 타겟과 같아진다면
		if (partial_tot == target)
			cnt++;
		
		//부분 합이 타겟m보다 작으면면 arr에 end를
		if (partial_tot < target)
			partial_tot += arr[end++];
		
		//부분 합이 타겟m보다 크면 arr에 처음부터
		else if (partial_tot >= target)
			partial_tot -= arr[start++];
	}
	return cnt;
}

void solution(void) {
	int n; 
	long long m;
	
	//입력
	cin >> n >> m;

	//동적할당
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int ret = two_pointer(arr, n, m);
	cout << ret << '\n';
	//메모리 해제
	delete[] arr;
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
