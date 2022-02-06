#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1000000;
int prime[MAX];
bool check[MAX + 1];
int p_idx;

int main(void ) {
    //소수 만들기
    check[0] = check[1] = true;
    for (int i = 2; i * i <= MAX; i++) {
        if (check[i] == false) {
            prime[p_idx++] = i;
            for (int j = i + i; j <= MAX; j += i)
                check[j] = true;
        }
    }

    while (true) {
        int n;

        cin >> n;

        if (n == 0)
            break;

        for (int i = 0; i < p_idx; i++) {
            if (check[n - prime[i]] == false) {
                printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
                break;
            }
        }
    }
    return 0;
}
