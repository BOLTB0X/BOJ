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

// 숫자중 고장난 버튼이 있는지 체크
int is_broken(int b) {
	// 0인 경우
	if (b == 0) {
		if (visited[0] == 0)
			return 1;
	}

	while (b > 0) {
		int r = b % 10;

		if (visited[r] == 0)
			return 1;

		b /= 10;
	}

	return 0;
}

int solution(int n, int m) {
	int answer = Abs(n - 100); // 수빈이는 100에서 시작하므로

	// -까지 생각해야하므로
	for (int i = 0; i < Max_Size; ++i) {
		// 고장나지 않았다면
		if (is_broken(i) == 0)
			answer = Min(Abs(n - i) + to_string(i).length(), answer);
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
