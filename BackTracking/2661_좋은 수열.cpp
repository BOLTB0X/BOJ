#include <iostream>
#include <string>

using namespace std;

int flag = 0;
string result;

// 좋은 수열인지 판단
int is_Good_sq(string sq) {
	int size = sq.length(); // 길이

	// 좌우 반전처럼 반복되어야하는데 2개씩 자르는데 같으면 0 반환
	for (int i = 2; i <= size; i += 2) {
		string cmp1 = sq.substr(size - (i / 2), i / 2); // 뒤
		string cmp2 = sq.substr(size - i, i / 2); // 앞

		// 같다면
		if (cmp1 == cmp2)
			return  0;
	}
	return 1;
}

void DFS(string number, int n) {
	// 답이 나온 경우
	if (flag == 1)
		return;

	// 탈출조건
	if (number.length() == n) {
		result = number;
		flag = 1;
		// atoi로 정수로 변환해 최솟값을 구하는 방식도 돼
		return;
	}

	// 1부터 순차적으로
	// 처음으로 등장하는 수열이 가장 작은 좋은 수열
	for (int i = 1; i <= 3; ++i) {
		number.push_back(i + '0'); // 삽입
		if (is_Good_sq(number) == 1) // 좋은 수열 경우 다시 DFS 호출
			DFS(number, n);
		number.pop_back(); // 팝
	}
	return;
}

string solution(int n) {
	string answer;

	//백트래킹 시작
	DFS("", n);
	answer = result;
	return answer;
}

int main(void) {
	int n;
	cin >> n;

	string ret = solution(n);
	cout << ret;
	return 0;
}