#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MLN 100001

int que[MLN];
int head = 0, tail = 0;
int visited[MLN];

void enqueue(int data) {
	que[tail++] = data;
	return;
}

void dequeue(void) {
	head++;
	return;
}

int solution(int n, int k) {
	int result = 0;
	memset(visited, 0, sizeof(int) * MLN);
	visited[n] = 1;
	enqueue(n);

	while (head != tail) {
		int cur = que[head];
		dequeue();

		if (cur == k)
			break;

		if (cur + 1 < MLN & visited[cur + 1] == 0) {
			visited[cur + 1] = visited[cur] + 1;
			enqueue(cur + 1);
		}
		if (cur - 1 >= 0 & visited[cur - 1] == 0) {
			visited[cur - 1] = visited[cur] + 1;
			enqueue(cur - 1);
		}
		if (cur * 2 < MLN & visited[cur * 2] == 0) {
			visited[cur * 2] = visited[cur] + 1;
			enqueue(cur * 2);
		}
	}
	result = visited[k] - 1;
	return result;
}

int main(void) {
	int n, k, ret;
	scanf("%d %d", &n, &k);
	
	ret = solution(n,k);

	printf("%d", ret);
	return 0;
}
