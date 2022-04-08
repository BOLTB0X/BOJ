#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int d, r, g;
}Inf;

int traffic(int idx, int time, vector<Inf>& v) {
	if (time % (v[idx].g + v[idx].r) <= v[idx].r)
		return 0;
	return 1;
}

int solution(int N, int L, vector<Inf>& v) {
	int answer = 0; // 시간
	int dist = 0, idx = 0;

	while (1) {
		if (dist == L)
			break;

		if (idx < v.size()) {
			// 신호등에 도착한다면
			if (v[idx].d == dist) {
				if (traffic(idx, answer, v) == 1) {
					dist++;
					answer++;
				}
				else {
					int tmp = answer % (v[idx].r + v[idx].g);
					answer = answer + (v[idx].r - tmp);
				}
				idx++;
				continue;
			}
		}
		answer++;
		dist++;
	}

	return answer;
}

int main(void) {
	int N, L;
	vector<Inf> v;

	cin >> N >> L;
	v.resize(N);

	for (int i = 0; i < N; ++i) 
		cin >> v[i].d >> v[i].r >> v[i].g;
	
	int ret = solution(N, L, v);
	cout << ret;
	return 0;
}