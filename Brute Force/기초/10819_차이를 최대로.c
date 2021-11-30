#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int result = -1;
int per[9] = { 0, };

//절댓값 반환
int abs(int a) {
	if (a < 0)
		return -a;
	return a;
}

//각 차이값
int get_dist(int n) {
	int tot = 0;
	for (int i = 0; i < n - 1; ++i)
		tot += abs(per[i] - per[i + 1]);

	return tot;
}

//깊이우선탐색
void DFS(int n, int* arr, int* visited, int depth) {
	//탈출조건
	if (depth == n) {
		//최댓값 교체
		if (result < get_dist(n))
			result = get_dist(n);
		return;
	}

	//순열
	for (int i = 0; i < n; ++i) {
		//예외처리
		if (visited[i] == 1)
			continue;
		per[depth] = arr[i];
		visited[i] = 1;
		DFS(n, arr, visited, depth + 1);
		visited[i] = 0;
	}

	return;
}

//해결함수
void solution(int n, int* arr) {
	//방문리스트
	int* visited = malloc(sizeof(int) * n);
	
	//원소 입력
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		visited[i] = 0;
	}

	//DFS로 순열
	DFS(n, arr, visited, 0);

	//출력
	printf("%d\n", result);

	//해제
	free(visited);
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);

	//동적할당
	int* arr = malloc(sizeof(int) * n);

	//초기화
	for (int i = 0; i < n; ++i)
		arr[i] = 0;

	//해결
	solution(n,arr);

	//해제
	free(arr);
	return 0;
}