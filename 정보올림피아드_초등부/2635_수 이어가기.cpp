#include <iostream>
#include <vector>

using namespace std;

void solution(void) {
	int n;
	int max_len = 0;
	vector<int> max_arr;

	cin >> n;
	
	for (int i = 0; i <= n; ++i) {
		vector<int> arr;
		arr.push_back(n);
		arr.push_back(i);
		int idx = 0;

		while (true) {
			int ele = arr[idx] - arr[idx + 1];

			if (ele <= -1)
				break;

			arr.push_back(ele);

			if (max_len < arr.size()) {
				max_len = arr.size();
				max_arr = arr;
			}
			idx++;
		}
	}

	cout << max_len << '\n';
	for (int i = 0; i < max_len; ++i) 
		cout << max_arr[i] << ' ';
	cout << '\n';
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}