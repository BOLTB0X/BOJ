#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void solution(void) {
	int N;
	cin >> N;
	
	vector<int> arr;

	for (int i = 1; i <= N; ++i) {
		int num = i;
		for (int j=2; j * j <= i;++j) {
			while (num % j == 0) {
				arr.push_back(j);
				num /= j;
			}
		}
		if (num > 1)
			arr.push_back(num);
	}

	int answer = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == 5)
			answer++;
	}
	cout << answer << '\n';

	return;
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}