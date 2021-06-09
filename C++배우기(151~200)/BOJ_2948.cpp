#include <iostream>
using namespace std;

int main(void) {
    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int m, d; //월 일 변수
    int answer = 0;
    cin >> d >> m;
    answer += d;
    for (int i = 0; i < (m - 1); i++) {
        answer += arr[i];
    }
    switch (answer % 7) {
    case 0:
        cout << "Wednesday";
        break;
    case 1:
        cout << "Thursday";
        break;
    case 2:
        cout << "Friday";
        break;
    case 3:
        cout << "Saturday";
        break;
    case 4:
        cout << "Sunday";
        break;
    case 5:
        cout << "Monday";
        break;
    case 6:
        cout << "Tuesday";
        break;
    }
    return 0;
}