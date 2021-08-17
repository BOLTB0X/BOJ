#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
struct compare {
	bool operator() (int x, int y) {
		return x > y;
	}
};

priority_queue<int,vector<int>,compare> pq;

int main(void) {
	int value;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &value);

		if (value == 0) {
			if (pq.empty())
				printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(value);
		}
	}
	return 0;
}
