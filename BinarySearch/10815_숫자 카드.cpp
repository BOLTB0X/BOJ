#include <iostream>
#include <algorithm>

using namespace std;

//이분탐색
int binary_search(int* arr, int size, int target) {
	int start = 0, end = size - 1;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == target)
			return 1;
		else if (arr[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}

void solution(void) {
	int n, m;
	cin >> n;
	int* cards = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> cards[i];
	}
	//이진탐색을 위한 오름차순
	sort(cards, cards + n);

	cin >> m;
	int* result = new int[m];

	for (int i = 0; i < m; ++i) {
		int target;
		cin >> target; 
		int is_card = binary_search(cards, n, target);
		result[i] = is_card;
	}

	//정답 출력
	for (int i = 0; i < m; ++i) {
		cout << result[i] << ' ';
	}
	cout << '\n';
	//메모리 해제
	delete[] cards;
	delete[] result;

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
