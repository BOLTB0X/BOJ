#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> per;

int main() {
	cin >> n;
	per.resize(n); //n크기로 벡터 설정

	for (int i = 0; i < n; i++) {
		cin >> per[i];
	}
	if (next_permutation(per.begin(),per.end())) {
		for (int i = 0; i < n; i++) {
			cout << per[i] << " ";
		}
	}
	else {
		cout << "-1";
	}
}