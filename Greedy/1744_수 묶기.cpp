#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[50];

bool compare(int& a, int& b) {
	return a > b;
}

int solution(int n) {
	int answer = 0, ptot = 0, ntot = 0, one = 0, zero = 0;
	vector<int> pos, neg, rest;

	for (int i = 0; i < n; ++i) {
		if (arr[i] > 1)
			pos.push_back(arr[i]);
		else if (arr[i] < 0)
			neg.push_back(arr[i]);
		else if (arr[i] == 1)
			one++;
		else
			zero++;
	}

	sort(pos.begin(), pos.end(), compare);

	// È¦¼ö ÀÌ¸é
	if (pos.size() % 2 != 0)
		pos.push_back(1);

	for (int i = 0; i < pos.size(); i += 2)
		ptot += (pos[i] * pos[i + 1]);

	if (neg.size() % 2 != 0)
		zero == 0 ? neg.push_back(1) : neg.push_back(0);
	
	sort(neg.begin(), neg.end());

	for (int i = 0; i < neg.size(); i += 2) 
		ntot += (neg[i] * neg[i + 1]);
	
	answer = ptot + ntot + one;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret = solution(n);
	cout << ret;
	return 0;
}