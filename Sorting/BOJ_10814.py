import sys
input=lambda :sys.stdin.readline().rstrip()
n=int(input())
inf=[]
for _ in range(n):
    age,name=input().split()
    inf.append([int(age),name])
inf.sort(key=lambda x:x[0])
for i in inf:
    print(*i)