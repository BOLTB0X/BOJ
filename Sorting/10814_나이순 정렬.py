#입출력
from sys import stdin
#입력 
input = stdin.readline

n=int(input())

arr=[]
for _ in range(n):
    age,name=input().split()
    arr.append([int(age),name])

#람다식을 이용한 정렬
arr.sort(key=lambda x:x[0])

for a in arr:
    print(*a)