#include <iostream>

using namespace std;

//최대
int max(float a, float b) {
	return a > b ? a : b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double result = -1, tot;
	
	//입력
	cin >> n;
	//동적할당
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//원소들이 소수점으로 들어있음
	//즉 작아지기도하고 커지기도 하므로
	//완전탐색
	for (int i = 0; i < n; i++) {
		tot = 1;
		for (int j = i; j < n; j++) {
			tot *= arr[j];
			result = max(result, tot);
		}
	}
	printf("%.3f\n", result);
	delete[] arr;
	return 0;
}