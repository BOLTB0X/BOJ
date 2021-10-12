#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int n, cnt = 0;
int map[25][25];
bool visited[25][25];

//이동방향 서남동북
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

void swap(int* a, int* b) {
	int* tmp = a;
	a = b;
	b = tmp;
}

void quicksort(vector<int> &arr, int start, int end) {
	if (start >= end)
		return;
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right) {
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		while (right > start && arr[right] >= arr[pivot])
			right--;
		if (left > right)
			swap(arr[pivot], arr[right]);
		else
			swap(arr[left], arr[right]);
	}
	quicksort(arr, start, right - 1);
	quicksort(arr, right + 1, end);
	return;
}

void DFS(int r, int c) {
	visited[r][c] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ny = r + dy[i];
		int nx = c + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		if (visited[ny][nx] || map[ny][nx] == 0)
			continue;
		DFS(ny, nx);
	}
	return;
}

int main(void) {
	scanf("%d", &n);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	vector<int> arr;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 1 &&!visited[y][x]) {
				cnt = 0;
				DFS(y, x);
				arr.push_back(cnt);
			}
		}
	}
	quicksort(arr, 0, arr.size() - 1);
	printf("%d\n", arr.size());
	for (int i = 0; i < arr.size(); i++) {
		printf("%d\n", arr[i]);
	}
	printf("\n");
	return 0;
}