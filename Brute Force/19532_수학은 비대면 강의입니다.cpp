#include <iostream>

using namespace std;

pair<int,int> solution(int a, int b, int c, int d, int e, int f) {
	pair<int, int> answer = { 0,0 };
	int flag = 0;

	for (int i = -999; i <= 999; ++i) {
		for (int j = -999; j <= 999; ++j) {
			if (a * i + b * j == c) {
				if (d * i + e * j == f) {
					answer.first = i, answer.second = j;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)
			break;
	}

	return answer;
}

int main(void) {
	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	pair<int, int> ret = solution(a, b, c, d, e, f);
	cout << ret.first << ' ' << ret.second;

	return 0;
}