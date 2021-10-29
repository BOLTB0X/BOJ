#입출력
from sys import stdin
#순열
from itertools import permutations
#입력 
input = stdin.readline

n=int(input())
A = list(map(int,input().split()))

#오름차순 정렬
A.sort()
result = -1

#순열
per = permutations(A,len(A))
for p in per:
    tmp = 0
    for i in range(len(p)-1):
        tmp += abs(p[i]-p[i+1])
    #확인
    result = max(result,tmp)
print(result)