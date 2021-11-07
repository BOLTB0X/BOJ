#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(void) {
	int n;
	cin >> n;

	//벡터 초기화
	//2차원 벡터
	vector<vector<int>> arr(n, vector<int>(2, 0));
	
	//입력
	for (int i = 0; i < n; i++) 
		cin >> arr[i][1] >> arr[i][0];

	//정렬
	sort(arr.begin(), arr.end());

	//출력만 바꿔서
	for (int i = 0; i < n; i++) 
		cout << arr[i][1] << ' ' << arr[i][0] << '\n';
	
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
