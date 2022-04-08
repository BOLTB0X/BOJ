#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

void solution(int n, vector<pair<int, string>> &arr) {
	// 정렬
	stable_sort(arr.begin(), arr.end(), compare);

	// 출력
	for (int i = 0; i < n; i++) 
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	
	return;
}

int main(void) {
	int n;
	vector<pair<int, string>> arr;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int age;
		string name;

		cin >> age >> name;
		arr.push_back({ age,name });
	}

	solution(n, arr);
	return 0;
}
