#직사각형 네개의 합집합의 면적 구하기
graph=[[0 for _ in range(101)] for _ in range(101)]
for _ in range(4):
    x1,y1,x2,y2=map(int,input().split())
    for i in range(x1,x2):
        for j in range(y1,y2):
            graph[i][j]=1
tot=0
for x in graph:
    tot+=sum(x)
print(tot)