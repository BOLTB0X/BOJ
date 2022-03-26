#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> chanel; // 채널
vector<int> visited;

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

// 절댓값 반환
int Abs(int a) {
	return a < 0 ? -a : a;
}

// 고장난 버튼인가?
int is_Broken(int number) {
	int div = 10;

	if (number == 0) {
		if (visited[0] == 1)
			return 0;
	}

	// 자리수 확인
	while (number != 0) {
		int mod = number % div;

		if (visited[mod] == 1)
			return 0;

		number /= div;
	}

	return 1;
}

int solution(int n, int m) {
	//1씩 증가시키는 방법이 최대 횟수
	int answer = abs(n - 100); // 수빈이 시작은 100이므로
	
	for (int i = 0; i <= 1000000; ++i) {
		// 고장난 버튼이 아니면
		if (is_Broken(i) == 1) {
			int tmp = abs(n - i) + to_string(i).length();
			answer = Min(answer, tmp);
		}
	}
	return answer;
}

int main(void) {
	int n, m;
	int x;

	cin >> n;
	chanel.resize(n + 1, 0);
	visited.resize(10, 0);
	
	cin >> m;
	
	for (int i = 0; i < m; ++i) {
		cin >> x;
		visited[x] = 1;
	}

	int ret = solution(n, m);
	cout << ret;

	return 0;
}
