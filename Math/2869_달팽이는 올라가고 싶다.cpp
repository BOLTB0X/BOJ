#include <iostream>

using namespace std;

int solution(int A, int B, int V) {
	int answer = 0;
	answer = (V - B - 1) / (A - B) + 1;
	return answer;
}

int main(void) {
	int A, B, V;

	cin >> A >> B >> V;

	int ret = solution(A, B, V);
	cout << ret;
	return 0;
}