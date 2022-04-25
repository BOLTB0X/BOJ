#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> solution(int A, int B, int m) {
	vector<int> answer;
	vector<int> v;
	int dec = 0;

	while (m--) {
		int tmp;

		cin >> tmp;
		dec += (tmp * pow(A, m));
	}

	while (dec > 0) {
		v.push_back((dec % B));
		dec /= B;
	}

	for (int i = v.size() - 1; i >= 0; --i)
		answer.push_back(v[i]);

	return answer;
}

int main(void) {
	int A, B, m;

	cin >> A >> B >> m;
	vector<int> ret = solution(A, B, m);
	for (int& r: ret)
		cout << r << ' ';
	return 0;
}