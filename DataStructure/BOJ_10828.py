#스택
import sys
input=lambda :sys.stdin.readline().rstrip()
T=int(input())
stack=list()
for i in range(T):
    comm,*n=input().split()
    if comm=='push':
        stack.append(int(n[0]))
    elif comm=='pop':
        print(stack.pop() if len(stack)>0 else -1)
    elif comm=='size':
        print(len(stack))
    elif comm=='empty':
        print(1 if len(stack)==0 else 0)
    elif comm=='top':
        print(stack[-1] if len(stack)>0 else -1)