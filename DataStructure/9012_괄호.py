from collections import deque
n=int(input())
for _ in range(n):
    string=input()
    dq=deque()
    check=len(string)
    for i in range(len(string)):
        if string[i]=='(':
            dq.append(string[i])
        elif string[i]==')':
            if len(dq)==0:
                print("NO")
                break
            dq.pop()
            check-=1