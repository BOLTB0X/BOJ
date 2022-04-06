#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n1, int n2, int T, string ant1, string ant2) {
	string answer;
	int size = n1 + n2;
	// ant1 -> , ant2 <-
	vector<pair<char, bool>> v;
	reverse(ant1.begin(), ant1.end());

	for (int i = 0; i < n1; ++i) 
		v.push_back({ ant1[i], 1 });
	
	for (int i=0; i < n2; ++i) 
		v.push_back({ ant2[i], 0});

	while (T--) {
		for (int i = 0; i < size - 1; ++i) {
			if (v[i].second == 1 && v[i + 1].second == 0) {
				swap(v[i], v[i + 1]);
				i++;
			}
		}
	}

	for (int i = 0; i < size; ++i)
		answer += v[i].first;
	
	return answer;
}

int main(void) {
	int n1, n2, T;
	string ant1, ant2;

	cin >> n1 >> n2;
	cin >> ant1 >> ant2;
	cin >> T;

	string ret = solution(n1, n2, T, ant1, ant2);
	cout << ret;
	return 0;
}