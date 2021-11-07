#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& A, const string& B) {
	// 크기 비교
	int A_size = A.length(), B_size = B.length();
	if (A_size != B_size) 
		return A_size < B_size;

	// 합 구하고 비교
	int A_sum = 0, B_sum = 0;
	for (int i = 0; i < A_size; i++) {
		if ('0' <= A[i] && A[i] <= '9')    
			A_sum += A[i] - '0';
		if ('0' <= B[i] && B[i] <= '9')    
			B_sum += B[i] - '0';
	}

	if (A_sum != B_sum) 
		return A_sum < B_sum;

	// 사전순 비교
	return A < B;
}

void solution(void) {
	int n;
	cin >> n;

	//벡터 초기화
	//2차원 벡터
	vector<string> arr(n);

	//입력
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	
	//정렬
	sort(arr.begin(), arr.end(), compare);

	//출력
	for (int i = 0; i < n; ++i)
		cout << arr[i] << '\n';

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