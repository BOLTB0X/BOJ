from itertools import permutations
#입출력
from sys import stdin
#입력 
input = stdin.readline

n,m=map(int,input().split())
arr=list(map(int,input().split()))

#set으로 중복제거
P=set(permutations(arr,m))

#다시 오름차순 정렬
ans_P=list(sorted(P))

for p in ans_P:
    print(*p)