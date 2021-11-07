#입출력
from sys import stdin
#입력 
input = stdin.readline

n=int(input())
points=[]

#입력
for _ in range(n):
    points.append(list(map(int,input().split())))

#정렬
points.sort(key= lambda x : (x[1],x[0]))

#출력
for point in points:
    print(*point)