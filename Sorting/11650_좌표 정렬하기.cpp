#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
	int x, y;

	bool operator < (const Pos& p) const {
		if (x == p.x)
			return y > p.y;
		return x > p.x;
	}
};
 
vector<pair<int, int>> solution(int n, vector<vector<int>>& points) {
	vector<pair<int, int>> answer;
	priority_queue<Pos> pq;

	for (vector<int>& point : points) 
		pq.push({ point[0], point[1] });
	
	while (!pq.empty()) {
		answer.push_back({ pq.top().x, pq.top().y });
		pq.pop();
	}
	
	return answer;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> points(n, vector<int>(2, 0));

	//입력
	for (int i = 0; i < n; i++)
		cin >> points[i][0] >> points[i][1];

	vector<pair<int,int>> ret = solution(n, points);
	for (pair<int, int>& r : ret)
		cout << r.first << ' ' << r.second << '\n';
	return 0;
}
