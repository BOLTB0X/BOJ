from itertools import permutations
#입출력
from sys import stdin
#입력 
input = stdin.readline

n,m=map(int,input().split())
arr=list(map(int,input().split()))

#오름차순
arr.sort()
P=list(permutations(arr,m))

for p in P:
    print(*p)