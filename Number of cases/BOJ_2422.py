from itertools import combinations
import sys
input = lambda :sys.stdin.readline().rstrip()
n,m=map(int,input().split())
ice=list(combinations(range(1,n+1),3))
no_mat = [[0] * (n+1) for _ in range(n+1)]
cnt=0
for _ in range(m):
    x,y=map(int,input().split())
    no_mat[x][y]=1
    no_mat[y][x]=1
for i in ice:
    if no_mat[i[0]][i[1]] or no_mat[i[0]][i[2]] or no_mat[i[1]][i[2]]:
        continue
    cnt += 1
print(cnt)