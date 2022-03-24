#include <iostream>
#include <vector>
#include <queue>
#define Max_Size 100000

using namespace std;

int result, cnt;

void BFS(int n, int k) {
	vector<int> visited(Max_Size + 1, 0); // �湮����Ʈ
	queue<pair<int, int>> que;

	que.push({ n, 0 });
	visited[n] = 1;

	while (!que.empty()) {
		pair<int, int> cur = que.front();
		visited[cur.first] = 1;
		que.pop();

		// ���� ���Դٸ�
		if (result && cur.first == k && cur.second == result)
			cnt++;

		// ���� �ߴٸ�
		if (!result && cur.first == k) {
			cnt++; // ī��Ʈ
			result =cur.second; // �ִ� �ð�
		}

		else {
			if (cur.first - 1 >= 0 && visited[cur.first - 1] == 0) 
				que.push({ cur.first - 1, cur.second + 1 });

			if (cur.first + 1 <= Max_Size && visited[cur.first + 1] == 0) 
				que.push({ cur.first + 1, cur.second + 1 });
			
			if (cur.first * 2 <= Max_Size && visited[cur.first * 2] == 0) 
				que.push({ cur.first * 2, cur.second + 1 });
		}
	}
	return;
}

vector<int> solution(int n, int k) {
	vector<int> answer;
	result = 0, cnt = 0;

	BFS(n, k);

	answer.push_back(result);
	answer.push_back(cnt);
	return answer;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	vector<int> ret = solution(n, k);
	cout << ret[0] << '\n' << ret[1];
	return 0;
}