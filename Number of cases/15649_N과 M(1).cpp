#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
bool visited[9];
vector<int> per;

void permutation(int n, int m, int depth) {
	if (depth == m) {
		for (int i = 0; i < per.size(); i++) {
			printf("%d ", per[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		per.push_back(i);
		permutation(n, m, depth + 1);
		per.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	permutation(n, m, 0);
	return 0;
}