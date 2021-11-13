#include <iostream>
#include <vector>

using namespace std;

//�Ҽ��Ǻ� �����佺�׳׽��� ü
void is_prime_number(int n, int k, vector<int>& primes) {
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		//i�� 2���� �����Ͽ� ����� ���ʷ� ����
		for (int j = i; j <= n; j += i) {
			if (primes[j] != 0) {
				primes[j] = 0;
				//� �������� üũ
				cnt++;

				//cnt ������ k�� �������� ������ k��° ������ ��
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
	
	//���� ������ �ʱ�ȭ
	vector<int> primes(n + 1, 0);
	for (int i = 2; i <= n; ++i)
		primes[i] = i;

	is_prime_number(n, k, primes);
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}