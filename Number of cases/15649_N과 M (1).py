#입출력
from sys import stdin
#입력 
input = stdin.readline
#순열
from itertools import permutations

n,m=map(int,input().split())

per = list(permutations([i for i in range(1,n+1)],m))

for p in per:
    print(*p)