#include <iostream>
using namespace std;

int main(void) {
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int m, d; //�� �� ����
	int answer = 0;
	cin >> m >> d;
	answer += d;
	for (int i = 0; i < (m - 1); i++) {
		answer += arr[i];
	}
    switch (answer % 7) {
    case 0:
        cout << "SUN";
        break;
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;
    case 5:
        cout << "FRI";
        break;
    case 6:
        cout << "SAT";
        break;
    }
    return 0;
}