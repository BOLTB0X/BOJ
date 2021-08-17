#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
	bool operator() (int x, int y) {
		if (abs(x) == abs(y))
			return x > y;
		else
			return abs(x) > abs(y);
	}
};

int main(void) {
	int n,value;
	priority_queue<int, vector<int>, compare> pq;
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