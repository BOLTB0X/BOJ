#include <iostream>
#include <vector>
#include <string>
#define Max_Size 1000001

using namespace std;

vector<bool> visited(Max_Size, 1); // 고장난 버튼 체크

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

// 절댓값 반환
int Abs(int a) {
	return a < 0 ? -a : a;
}

// 고장 판별
int is_broken(int butten) {
	if (butten == 0) {
		if (visited[0] == 0)
			return 1;
	}

	// 각 자리수 체크
	while (butten > 0) {
		int mod = butten % 10;

		// 고장난 버튼
		if (visited[mod] == 0)
			return 1;

		butten /= 10;
	}

	return 0;
}

int solution(int n, int m) {
	int answer = Abs(n - 100); // 수빈이는 100에서 시작하므로

	for (int i = 0; i < Max_Size; ++i) {
		// i가 고장나지 않았다면
		if (is_broken(i) == 0) {
			int tmp = Abs(n - i) + to_string(i).length();
			answer = Min(answer, tmp);
		}
	}

	return answer;
}

int main(void) {
	int n, m;
	int a;

	cin >> n >> m;
	
	for (int i = 0; i < m; ++i) {
		cin >> a;
		visited[a] = 0;
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
