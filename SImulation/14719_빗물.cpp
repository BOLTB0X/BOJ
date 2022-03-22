#include <iostream>

using namespace std;

int heights[501];

int Max(int a, int b) {
	return a > b ? a : b;
}

int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int H, int W) {
	int answer = 0;
	// 고일수 있는 영역을 생각해야함
	// 너비 w중 2 ~ w-1 구간에서 고이는 부분이 결정남
	// 2부터 탐색하면서 L,R을 선언해 왼, 우를 비교하면서 작은 값이 기준이 됌

	for (int i = 2; i < W; ++i) {
		int left = 0, right = 0;

		// 왼쪽부터 자기 위치 전까지
		for (int j = 1; j < i; ++j)
			left = Max(left, heights[j]);
		
		// 오른쪽 끝까지
		for (int j = i + 1; j <= W; ++j)
			right = Max(right, heights[j]);

		// 현재 물의 양
		// 왼쪽 오른쪽 중 작은 값에서 현재 값을 빼줌
		int cur_w = Min(left, right) - heights[i];

		// 양수이면
		if (cur_w >= 0)
			answer += cur_w;
	}

	// 반환
	return answer;
}

int main(void) {
	int H, W;

	cin >> H >> W;
	for (int i = 1; i <= W; ++i) 
		cin >> heights[i];
	
	int ret = solution(H, W);
	cout << ret;

	return 0;
}