#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int value;
		scanf("%d", &value);

		if (value == 0) {
			if (pq.empty()) 
				printf("0\n");
			else {
				int p = pq.top();
				pq.pop();
				printf("%d\n",p);
			}
		}
		else {
			pq.push(value);
		}
	}
	return 0;
}