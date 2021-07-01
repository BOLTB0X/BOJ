#include<iostream>
using namespace std;

int n;

int combination(int n, int r) {
    if (n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(void) {
    cin >> n;
    cout << n * (n - 1) * (n - 2) * (n - 3) / 24 << '\n';
    cout << combination(n, 4) << '\n';
}