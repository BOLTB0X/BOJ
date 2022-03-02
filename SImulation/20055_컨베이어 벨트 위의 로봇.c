#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MS 201

typedef struct {
	int d, flag;
} Block;

Block belt[MS];

//종료되는 지 체크
int check(int n, int k) {
	int cnt = 0;

	for (int i = 1; i <= 2 * n; ++i) {
		if (belt[i].d == 0)
			cnt++;
	}

	return cnt >= k ? 1 : 0;
}

//회전
void belt_rotate(int n, int k) {
	Block tmp = belt[2 * n];

	// - > 방향으로 회전
	for (int i = 2 * n - 1; i >= 1; --i)
		belt[i + 1] = belt[i];
	belt[1] = tmp;

	//회전 후 로봇을 내리는 위치에 로봇이 있다면
	if (belt[n].flag == 1)
		belt[n].flag = 0;

	return;
}

//이동
void move(int n, int k) {
	//거꾸로
	//1부터 시작하면 기존 내리는 위치가 애매해짐
	for (int i = n - 1; i >= 1; --i) {
		//로봇이 있다면
		if (belt[i].flag == 1) {
			//다음 칸에 내구도가 1 이상이고 로봇이 없다면
			if (belt[i + 1].d >= 1 && belt[i + 1].flag == 0) {
				belt[i].flag = 0;
				belt[i + 1].d--;
				belt[i + 1].flag = 1;
			}
		}
	}

	//회전 후 로봇을 내리는 위치에 로봇이 있다면
	if (belt[n].flag == 1)
		belt[n].flag = 0;

	return;
}

//첫 번재 칸에 로봇 삽입
void input_robot(int n, int k) {
	//내구도도 1 이상이고 로봇이 없다면
	if (belt[1].d >= 1 && belt[1].flag == 0) {
		belt[1].flag = 1;
		belt[1].d--;
	}
	
	return;
}

int solution(int n, int k) {
	int answer = 0;

	//시뮬 시작
	while (1) {
		if (check(n, k) == 1) //4번 조건
			break;
		answer++;
		belt_rotate(n, k); //1번 조건 벨트 회전
		move(n, k); // 2번 조건 로봇 이동
		input_robot(n, k); //3번 조건 로봇 올리기
	}
	return answer;
}

int main(void) {
	int n, k;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= 2 * n; ++i) {
		int d;
		scanf("%d", &d);
		belt[i].d = d;
		belt[i].flag = 0; // 로봇이 있는지 체크
	}
	
	int ret = solution(n, k);
	printf("%d", ret);

	return 0;
}