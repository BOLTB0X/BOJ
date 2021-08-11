#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main(void) {
	int n;
	vector<pair<int, string>> arr;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int age;
		string name;

		cin >> age >> name;
		arr.push_back({age,name});
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
	return 0;
}