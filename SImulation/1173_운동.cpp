#include<iostream>

using namespace std;

int solution(int N, int m, int M, int T, int R) {
	int answer = 0;
	// N�� ��� ��, m�� �ʱ� �ƹ�, M ���� �ƹ�, T ���� �ƹ�, R �޽� �� ���� �ƹ�
	int cur_m = m; // ���� �ƹ�

	// ��� ���� ���
	if (M - m < T)
		answer = -1;
	else {
		// �ù� ����
		while (N > 0) {
			if (cur_m + T <= M) {
				cur_m += T;
				N--;
			}
			// �޽�
			else {
				cur_m -= R;
				if (cur_m < m)
					cur_m = m;
			}
			answer++;
		}
	}
 
	return answer;
}

int main(void) {
	int N, m, M, T, R;

	cin >> N >> m >> M >> T >> R;
	int ret = solution(N, m, M, T, R);
	cout << ret;
	return 0;
}