from itertools import combinations
#입출력
from sys import stdin
#입력 
input = stdin.readline

while True:
    k,*s=map(int,input().split())
    if k==0:
        break
    C=list(combinations(s,6))

    for c in C:
        print(*c)
    print()