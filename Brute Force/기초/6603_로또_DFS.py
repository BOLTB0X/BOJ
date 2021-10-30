#입출력
from sys import stdin
#입력 
input = stdin.readline

#깊이우선탐색
def DFS(start, depth):
    #탈출조건
    if depth == 6:
        for i in range(6):
             print(com[i], end=' ')
        print()
        return

    for i in range(start, len(s)):
        com[depth] = s[i]
        DFS(i + 1, depth + 1)

com = [0]*13

while True:
    s = list(map(int, input().split()))
    if s[0] == 0:
        break
    del s[0]
    #호출
    DFS(0, 0)
    print()