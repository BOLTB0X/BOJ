#include <iostream>
#include <vector>

using namespace std;

//절댓값 반환
int abs(int a) {
	return a < 0 ? -a : a;
}

//맨하탄거리
int manhattan_dist(pair<int,int> a, pair<int,int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

//깊이 우선 탐색
void DFS(vector<vector<int>>& graph, vector<bool>& visited, int depth) {
	visited[depth] = true;

	for (int i = 0; i < graph[depth].size(); ++i) {
		int next = graph[depth][i];
		if (visited[next])
			continue;
		DFS(graph, visited, next);
	}
	return;
}

void simulation(int T) {
	while (T--) {
		int n;
		cin >> n;
		//생성 및 초기화
		vector<vector<int>> graph(n + 2);
		vector<bool> visited(n + 2, false);
		vector<pair<int, int>> pos;
		
		//좌표입력
		for (int i = 0; i < n + 2; ++i) {
			int y, x;
			cin >> y >> x;
			pos.push_back({ y,x });
		}

		//그래프에 표시
		for (int i = 0; i < n + 2; ++i) {
			for (int j = i + 1; j < n + 2; ++j) {
				//맨하탄거리가 1000보다 작거나 같으면
				if (manhattan_dist(pos[i], pos[j]) <= 1000) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		//DFS탐색 시작
		DFS(graph, visited, 0);

		//결과
		if (visited[n + 1])
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	return;
}

void solution(void) {
	int T;
	cin >> T;

	simulation(T);
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
