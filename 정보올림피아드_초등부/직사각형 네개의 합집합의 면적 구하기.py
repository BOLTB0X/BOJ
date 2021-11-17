from sys import stdin
#입력
input = stdin.readline

#그래프 생성
graph = [[0 for _ in range(101)] for _ in range(101)]

#각 좌표입력
for _ in range(4):
    x1,y1,x2,y2 = map(int,input().split())
    #행부터
    for x in range(x1,x2):
        for y in range(y1,y2):
            graph[x][y] = 1

tot = 0

#저장된 그래프 
for g in graph:
    tot += sum(g)
    
#출력
print(tot)