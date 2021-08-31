#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

//n+출발점+도착점
vector<int> graph[102];
bool visited[102];

//초기화
void init() {
	for (int i = 0; i < 102; i++) {
		graph[i].clear();
	}
	memset(visited, false, sizeof(visited));
}

//맨하탄거리
int manhattan_distance(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

//정석 DFS
void DFS(int cur) {
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (!visited[next])
			DFS(next);
	}
}

//시뮬레이션
void solution() {
	//시작전 초기화
	init();
	int n;
	vector<pair<int,int>> pos;
	cin >> n;
	//편의점 갯수 외 출발,도착 이므로
	for (int j = 0; j < n + 2; j++) {
		int y, x;
		cin >> y >> x;
		pos.push_back(make_pair(y,x)); //위치 저장
	}
	//조건에 해당하는 그래프생성
	for (int j = 0; j < n + 2; j++) {
		for (int k = j + 1; k < n + 2; k++) {
			//맨하탄거리가 1000보다 작거나 같으면
			if (manhattan_distance(pos[j], pos[k]) <= 20 * 50) {
				graph[j].push_back(k);
				graph[k].push_back(j);
			}
		}
	}
	DFS(0); //시작0으로 DFS시작
	//맥주를 못마셨으면 방문X;
	if (visited[n + 1])
		cout << "happy" << '\n';
	else
		cout << "sad" << '\n';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin >> test;
	//테스트 실행
	for (int t = 0; t < test; t++) {
		solution();
	}
	return 0;
}