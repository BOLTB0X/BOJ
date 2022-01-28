#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int que[100001];
int head = 0, tail = 0;
int visited[100001];

void enqueue(int data) {
	que[tail++] = data;
	tail = tail % 100001;
}

void dequeue(void) {
	head++;
	head = head % 100001;
}

void solution(void) {
	int n, k, result;
	scanf("%d %d", &n, &k);
	memset(visited, 0, sizeof(int) * 100001);
	visited[n] = 1;
	enqueue(n);

	while (head != tail) {
		int cur = que[head];
		dequeue();

		if (cur == k)
			break;

		if (cur + 1 < 100001 & !visited[cur + 1]) {
			visited[cur + 1] = visited[cur] + 1;
			enqueue(cur + 1);
		}
		if (cur - 1 >= 0 & !visited[cur - 1]) {
			visited[cur - 1] = visited[cur] + 1;
			enqueue(cur - 1);
		}
		if (cur * 2 < 100001 & !visited[cur * 2]) {
			visited[cur * 2] = visited[cur] + 1;
			enqueue(cur * 2);
		}
	}
	result = visited[k] - 1;
	printf("%d", result);
	return;
}

int main(void) {
	solution();
	return 0;
}