#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

struct student {
	int weight, height;
};

int n;
student arr[51];

int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int w, h;
		student imf;
		scanf("%d %d", &w, &h);
		imf.weight = w;
		imf.height = h;
		arr[i]=imf;
	}
	int rank;
	//정렬 시작 투 포인터 알고리즘 이용
	for (int i = 0; i < n; i++) {
		rank = 1;
		for (int j = 0; j < n; j++) {
			if (arr[i].weight < arr[j].weight &&
				arr[i].height < arr[j].height)
				rank++;
		}
		printf("%d ", rank);
	}
	printf("\n");
	return 0;
}