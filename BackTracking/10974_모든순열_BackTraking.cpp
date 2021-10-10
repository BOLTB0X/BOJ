#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> per;
bool visited[9] = { false, };

void print_vector() {
	for (int i = 0; i < n; ++i) {
		cout << per[i] << ' ';
	}
	cout << '\n';
	return;
}

void DFS(int depth) {
	if (depth == n) {
		print_vector();
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (visited[i])
			continue;
		visited[i] = true;
		per.push_back(i);
		DFS(depth + 1);
		visited[i] = false;
		per.pop_back();
	}
}

void permutation(void) {
	cin >> n;
	DFS(0);
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	permutation();
	return 0;
}