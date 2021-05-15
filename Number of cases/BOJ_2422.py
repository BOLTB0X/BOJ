#한윤정이 이탈리아에 가서 아이스크림을 사먹는데
from itertools import combinations
import sys
input=lambda :sys.stdin.readline().rstrip()
n,m=map(int,input().split())
ice=list(combinations(range(1,n+1),m))
mat=[[0]*(n+1) for _ in range(n+1)]
for i in range(m):
    x,y=map(int,input().split())
    mat[x][y]=1
    mat[y][x]=1
ans=0
for x in ice:
    if mat[x[0]][x[1]] or mat[x[0]][x[2]] or mat[x[1]][x[2]]:
        continue
    ans+=1
print(ans)
