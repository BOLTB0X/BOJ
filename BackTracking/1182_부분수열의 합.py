#입출력
from sys import stdin
#입력 
input = stdin.readline

n,s=map(int,input().split())
arr=list(map(int,input().split()))

#dfs 이용
def DFS(i,tot): 
    global cnt;
    # 인덱스가 범위 초과시
    if i >=n: 
        return
    
    #리스트의 원소 더하고
    tot+=arr[i]
    
    #목표와 같은지 비교
    if tot==s: 
        cnt+=1
    
    #그 전의 합과 인덱스+1로 탐색
    DFS(i+1,tot-arr[i]) 
    #합과 인덱스+1 로 탐색
    DFS(i+1,tot)

cnt=0;
DFS(0,0)
print(cnt)