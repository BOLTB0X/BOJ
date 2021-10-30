#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(void) {
	int n;
	vector<int> per;
	vector<bool> visited;
	
	while (true) {
		//입력
		cin >> n;

		//탈출
		if (n == 0) 
			return ;

		per.resize(n);
		visited.resize(n);

		for (int i = 0; i < n; ++i) 
			cin >> per[i];

		for (int i=0; i < 6;++i )
			visited[i] = true;

		//오름 차순 정렬
		sort(per.begin(), per.end());

		//이전순열
		do {
			for (int i = 0; i < n; ++i) {
				if (visited[i])
					cout << per[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(visited.begin(), visited.end()));
		cout << '\n';
	}

	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}