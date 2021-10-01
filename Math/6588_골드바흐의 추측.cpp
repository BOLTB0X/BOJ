#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

const int MAX = 1000000;
int prime[MAX];
bool check[MAX + 1];
int pn;

int main() {
    check[0] = check[1] = true;
    for (int i = 2; i * i <= MAX; i++) {
        if (check[i] == false) {
            prime[pn++] = i;
            for (int j = i + i; j <= MAX; j += i)
                check[j] = true;
        }
    }

    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i < pn; i++) {
            if (check[n - prime[i]] == false) {
                printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
                break;
            }
        }
    }
    return 0;
}