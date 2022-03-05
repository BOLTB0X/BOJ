#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int que[5001];
int head = 0, tail = 0;

void enqueue(int data) {
	que[tail++] = data;
	tail = tail % 5001;
	return;
}

void dequeue(void) {
	head++;
	head = head % 5001;
	return;
}

void solution(int n, int k) {
	int tmp;
	
	//idx 큐에 삽입
	for (int i = 1; i <= n; ++i)
		enqueue(i);
	
	//k - 1만큼 회전
	for (int i = 1; i < k; ++i) {
		tmp = que[head];
		dequeue();
		enqueue(tmp);
	}

	printf("<%d", que[head]);
	dequeue();
	while (head != tail) {
		//k - 1만큼 회전
		for (int i = 1; i < k; ++i) {
			int tmp = que[head];
			dequeue();
			enqueue(tmp);
		}
		//pop
		printf(", %d", que[head]);
		dequeue();
	}
	printf(">");
	return;
}

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);

	solution(n, k);
	return 0;
}
