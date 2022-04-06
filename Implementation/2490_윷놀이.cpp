#include <iostream>

using namespace std;

char solution(int arr[4]) {
	int cnt = 0;
	
	// น่ 0 ต๎ 1
	for (int i = 0; i < 4; ++i) {
		if (arr[i] == 1)
			cnt++;
	}

	if (cnt == 3)
		return 'A';
	else if (cnt == 2)
		return 'B';
	else if (cnt == 1)
		return 'C';
	else if (cnt == 0)
		return 'D';
	else if (cnt == 4)
		return 'E';
}

int main(void) {
	for (int i = 0; i < 3; ++i) {
		int arr[4];
		for (int j = 0; j < 4; ++j)
			cin >> arr[j];
		
		char ret = solution(arr);
		cout << ret << '\n';
	}
	return 0;
}