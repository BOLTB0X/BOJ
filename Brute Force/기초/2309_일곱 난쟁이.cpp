#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(int* arr, int idx1, int idx2) {
	int tot = 0;

	for (int i = 0; i < 9; ++i) {
		if (i == idx1 || i == idx2)
			continue;
		tot += arr[i];
	}
	
	return tot == 100 ? 1 : 0;
}

vector<int> solution(int* arr) {
	vector<int> answer;
	int flag = 0;

	for (int i = 0; i < 8; ++i) {
		for (int j = i + 1; j < 9; ++j)
		if (check(arr, i, j) == 1) {
			arr[i] = -1;
			arr[j] = -1;
			flag = 1;
			break;
		}
		if (flag == 1)
			break;
	}

	for (int i = 0; i < 9; ++i) {
		if (arr[i] == -1)
			continue;
		answer.push_back(arr[i]);
	}
	return answer;
}

int main(void) {
	int* arr = new int[9];

	for (int i = 0; i < 9; ++i) 
		cin >> arr[i];
	
	vector<int> ret = solution(arr);
	sort(ret.begin(), ret.end()); // 오름차순 정렬
	for (int& r : ret) 
		cout << r << '\n';
	
	delete[] arr;
	return 0;
}