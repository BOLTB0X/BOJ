#include <iostream>
#include <string>

using namespace std;

int result = 0;
string words[50];
bool alp_occ[26] = { false, };

// 최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

//읽을 수 있는 단어 체크
int get_couted_words(int n) {
	int read_word = 0; // 학습 후 읽을 수 있는 단어
	for (int i = 0; i < n; ++i) { // 총 단어 확인
		int flag = 1;
		string word = words[i]; // 읽어볼 단어
		int size = word.length(); // 길이
		for (int j = 0; j < size; ++j) { // 해당 단어 문자 확인
			// 모르는 글자이면
			if (!alp_occ[words[i][j] - 'a']) {
				flag = 0;
				break;
			}
		}

		// 읽을 수 있다면
		if (flag == 1)
			read_word++;
	}
	return read_word;
}

// 조합
void DFS(int n, int k, int cur, int level) {
	if (level == k) {
		// 해당 조합으로 몇개 읽을 수 있느지 체크
		int read_word = get_couted_words(n);
		result = Max(result, read_word);
		return;
	}

	for (int i = cur; i < 26; ++i) {
		if (alp_occ[i]) // 이미 학습했다면
			continue;
		alp_occ[i] = 1;
		DFS(n, k, i + 1, level + 1);
		alp_occ[i] = 0;
	}

	return;
}

int solution(int n, int k) {
	int answer = 0;
	// k 개수만큼 단어를 조합
	// 그 조합에서 없는 단어는 못읽음
	// 남극 단어는 무조건 a,n,t,i,c로만 끝나므로

	// 백트래킹으로 k 개 문자를 학습시키고
	// 해당 단어를 읽을 수 있는지 체크
	// 단어를 읽는 조건 자체가 5개 문자를 읽어야 하므로 k를 -5해주고
	// antic를 학습시키고 조합을 진행
	string antic = "antic";
	for (int i = 0; i < 5; ++i)
		alp_occ[antic[i] - 'a'] = 1;

	// 조합 진행
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

	// 어차피 못 읽음
	if (k < 5)
		cout << '0';

	else {
		int ret = solution(n, k);
		cout << ret;
	}
	return 0;
}