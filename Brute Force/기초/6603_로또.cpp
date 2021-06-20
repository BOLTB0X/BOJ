#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		vector<int> com(n);
		vector<bool> visited(n);

		for (int i = 0; i < 6; i++) {
			visited[i] = true;
		}
		for (int i = 0; i < n; i++) {
			cin >> com[i];
		}
		sort(com.begin(), com.end());

		do {
			for (int i = 0; i < n; i++) {
				if (visited[i]) {
					cout << com[i] << " ";
				}
			}
			cout << "\n";
		} while (prev_permutation(visited.begin(), visited.end()));
		cout << '\n';
	}
	return 0;
}