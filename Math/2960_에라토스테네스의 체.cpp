#include <iostream>
#include <vector>

using namespace std;

//소수판별 에라토스테네스의 체
void is_prime_number(int n, int k, vector<int>& primes) {
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		//i를 2부터 시작하여 배수를 차례로 지움
		for (int j = i; j <= n; j += i) {
			if (primes[j] != 0) {
				primes[j] = 0;
				//몇개 지웠는지 체크
				cnt++;

				//cnt 변수가 k와 같아지는 순간이 k번째 지워진 수
				if (cnt == k) {
					cout << j << '\n';
					return;
				}
			}
		}
	}
	return;
}

void solution(void) {
	int n, k;
	cin >> n >> k;
	
	//벡터 사이즈 초기화
	vector<int> primes(n + 1, 0);
	for (int i = 2; i <= n; ++i)
		primes[i] = i;

	is_prime_number(n, k, primes);
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}