#include <iostream>
#include <string>

using namespace std;

int result = 0;
string words[50];
bool alp_occ[26] = { false, };

// �ִ� ��ȯ
int Max(int a, int b) {
	return a > b ? a : b;
}

//���� �� �ִ� �ܾ� üũ
int get_couted_words(int n) {
	int read_word = 0; // �н� �� ���� �� �ִ� �ܾ�
	for (int i = 0; i < n; ++i) { // �� �ܾ� Ȯ��
		int flag = 1;
		string word = words[i]; // �о �ܾ�
		int size = word.length(); // ����
		for (int j = 0; j < size; ++j) { // �ش� �ܾ� ���� Ȯ��
			// �𸣴� �����̸�
			if (!alp_occ[words[i][j] - 'a']) {
				flag = 0;
				break;
			}
		}

		// ���� �� �ִٸ�
		if (flag == 1)
			read_word++;
	}
	return read_word;
}

// ����
void DFS(int n, int k, int cur, int level) {
	if (level == k) {
		// �ش� �������� � ���� �� �ִ��� üũ
		int read_word = get_couted_words(n);
		result = Max(result, read_word);
		return;
	}

	for (int i = cur; i < 26; ++i) {
		if (alp_occ[i]) // �̹� �н��ߴٸ�
			continue;
		alp_occ[i] = 1;
		DFS(n, k, i + 1, level + 1);
		alp_occ[i] = 0;
	}

	return;
}

int solution(int n, int k) {
	int answer = 0;
	// k ������ŭ �ܾ ����
	// �� ���տ��� ���� �ܾ�� ������
	// ���� �ܾ�� ������ a,n,t,i,c�θ� �����Ƿ�

	// ��Ʈ��ŷ���� k �� ���ڸ� �н���Ű��
	// �ش� �ܾ ���� �� �ִ��� üũ
	// �ܾ �д� ���� ��ü�� 5�� ���ڸ� �о�� �ϹǷ� k�� -5���ְ�
	// antic�� �н���Ű�� ������ ����
	string antic = "antic";
	for (int i = 0; i < 5; ++i)
		alp_occ[antic[i] - 'a'] = 1;

	// ���� ����
	k -= 5;
	DFS(n, k, 0, 0);
	answer = result;
	return answer;
}

int main(void) {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> words[i];

	// ������ �� ����
	if (k < 5)
		cout << '0';

	else {
		int ret = solution(n, k);
		cout << ret;
	}
	return 0;
}