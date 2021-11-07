#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution() {
	int n;
	cin >> n;
	
	//좌표벡터 선언
	//열벡터를 2로 초기화
	vector<vector<int>> points(n,vector<int>(2,0));

	//입력
	for (int i = 0; i < n; i++) 
		cin >> points[i][0] >> points[i][1];
	
	//정렬
	sort(points.begin(), points.end());

	//출력
	for (int i = 0; i < n; i++) 
		cout << points[i][0] << ' ' << points[i][1] << '\n';
	
	return;
}

int main() {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
