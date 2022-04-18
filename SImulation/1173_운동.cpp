#include<iostream>

using namespace std;

int solution(int N, int m, int M, int T, int R) {
	int answer = 0;
	// N은 운둥 분, m은 초기 맥박, M 제한 맥박, T 증가 맥박, R 휴식 후 감소 맥박
	int cur_m = m; // 현재 맥박

	// 운동을 못할 경우
	if (M - m < T)
		answer = -1;
	else {
		// 시뮬 시작
		while (N > 0) {
			if (cur_m + T <= M) {
				cur_m += T;
				N--;
			}
			// 휴식
			else {
				cur_m -= R;
				if (cur_m < m)
					cur_m = m;
			}
			answer++;
		}
	}
 
	return answer;
}

int main(void) {
	int N, m, M, T, R;

	cin >> N >> m >> M >> T >> R;
	int ret = solution(N, m, M, T, R);
	cout << ret;
	return 0;
}