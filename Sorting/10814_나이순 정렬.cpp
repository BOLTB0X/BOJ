#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//숫자로 정렬
bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

void solution(void) {
	int n;
	vector<pair<int, string>> arr;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int age;
		string name;

		cin >> age >> name;
		arr.push_back({age,name});
	}
	//정렬
	stable_sort(arr.begin(), arr.end(), compare);

	//출력
	for (int i = 0; i < n; i++) 
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	
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
