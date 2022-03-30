#include <iostream>

using namespace std;

typedef struct {
	int d;
	int robot;
} Block;

Block belts[201];

// 멈추는 가?
int is_break(int n, int k) {
	int cnt = 0;

	// 내구도 세기
	for (int i = 1; i <= 2 * n; ++i) {
		if (belts[i].d == 0)
			cnt++;
	}

	return cnt >= k ? 1 : 0;
}

// 회전
void belts_Rotate(int n, int k) {
	Block tmp = belts[2 * n];

	for (int i = (2 * n) - 1; i >= 1; --i)
		belts[i + 1] = belts[i];

	belts[1] = tmp;

	// 내리는 칸에 로봇이 있다면
	if (belts[n].robot == 1)
		belts[n].robot = 0;
	return;
}

// 로봇 이동
void robot_Move(int n, int k) {
	for (int i = n - 1; i >= 1; --i) {
		// 현재 칸에 로봇이 있고
		if (belts[i].robot == 1) {
			// 다음 칸에 로봇이 없고 내구도가 1 이상이면
			if (belts[i + 1].robot == 0 && belts[i + 1].d >= 1) {
				belts[i].robot = 0;
				belts[i + 1].robot = 1;
				belts[i + 1].d--;
			}
		}
	}
	// 내리는 칸에 로봇이 있다면
	if (belts[n].robot == 1)
		belts[n].robot = 0;

	// 로봇 올리기
	if (belts[1].d >= 1 && belts[1].robot == 0) {
		belts[1].d--;
		belts[1].robot = 1;
	}

	return;

}

int solution(int n, int k) {
	int answer = 0;

	while (1) {
		if (is_break(n, k) == 1)
			break;

		belts_Rotate(n, k);
		robot_Move(n, k);
		answer++;
	}

	return answer;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> belts[i].d;
		belts[i].robot = 0;
	}

	int ret = solution(n, k);
	cout << ret;
	return 0;
}