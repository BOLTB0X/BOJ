#문자열 반복 https://www.acmicpc.net/problem/2675
t=int(input())
for _ in range(t):
    r,s=map(str,input().split())
    p=''
    for i in range(len(s)):
        p=p+(int(r)*s[i])
    print(p)