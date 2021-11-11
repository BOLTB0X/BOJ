#입출력
from sys import stdin
#입력 
input = stdin.readline

#깊이우선탐색
def DFS(arr,n,depth,p,tot):
    global result
    if depth == n:
        if result < tot:
            result = tot
        return
    
    elif depth > n:
        tot -= p
        if result < tot:
            result = tot
        return
    
    for i in range(depth,n):
        DFS(arr,n,i+arr[i][0],arr[i][1],tot+arr[i][1])
        
n=int(input())
#결과
result = -5000

#걸리는 일 수, 금액 리스트
arr = []
for _ in range(n):
    d,p=map(int,input().split())
    arr.append((d,p))

#깊이우선탐색 이용
DFS(arr,n,0,0,0)

#출력
print(result)