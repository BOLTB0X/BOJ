#include <utility>
#include <iostream>
using namespace std;

int n;

int main() {
	int rank;
	cin >> n;
	if (n < 2 || n > 50) return 0; //제한 사항

	pair<int, int>* arr = new pair<int, int>[n]; //(a,b)를 받는 배열 선언
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < n; i++) { //투 포인터 알고리즘 대상1을 셋팅하고 대상2를 돌리며 순위계산
		rank = 1; //대상1이 변환될때 마다 랭크 측정
		for (int j = 0; j < n; j++) {
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) rank++; //조건이 되면 증가
		}
		cout << rank << ' ';
	}
	cout << '\n';

	return 0;
}