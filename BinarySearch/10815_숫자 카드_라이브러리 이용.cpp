#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solution(int n, int m, vector<int>& cards, vector<int>& targets) {
	int *result = new int[m];
	
	//이진탐색을 위한 정렬
	sort(cards.begin(), cards.end());
	for (int i = 0; i < m; ++i) {
		bool is_card = binary_search(cards.begin(), cards.end(),targets[i]);
		result[i] = is_card;
		
	}
	
	for (int i = 0; i < m; ++i)
		cout << result[i] << ' ';
	cout << '\n';
	delete[] result;
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	vector<int> cards;
	vector<int> targets;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cards.push_back(a);
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		targets.push_back(a);
	}

	solution(n, m,cards, targets);
	return 0;
}