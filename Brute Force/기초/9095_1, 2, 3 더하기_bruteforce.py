#입출력
from sys import stdin
#입력 
input = stdin.readline

def recur(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    if n == 3:
        return 4
    else:
        return recur(n-1)+recur(n-2)+recur(n-3)

T = int(input())

for _ in range(T):
    n = int(input())
    result = recur(n)
    print(result)