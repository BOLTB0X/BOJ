#include <iostream>
#include <string>
using namespace std;

char s[3][8] = {};

int solution(int i) {
	int cnt = 1; //�Ϲ� ī��Ʈ ����
	int max_cnt = 1; //�ִ� ī��Ʈ ����
	char oj = s[i][0]; //�� ���� 1���� ù �񱳴������ ���� 
	for (int j = 1; j < 9; j++) { //Ž�� ����
		if (s[i][j] == oj) cnt += 1; //���ӵǸ� ī��Ʈ
		else { //�ٸ� ��� 
			if (cnt > max_cnt) max_cnt = cnt; //��ü
				oj = s[i][j];
				cnt = 1;
		}
	}
	return max_cnt;
}

int main(void) {
	for (int i = 0; i < 3; i++) {
		cin >> s[i];
		cout << solution(i) << '\n';
	}
	return 0;
}