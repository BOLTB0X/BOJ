#입출력
from sys import stdin
#입력 
input = stdin.readline

#테스트 입력
T=int(input())
stack=[]

for _ in range(T):
    #명령어 입력
    comm=list(input().split())
    #push
    if comm[0] == "push":
        stack.append(int(comm[1]))
    
    #top
    elif comm[0] == "top":
        print(stack[-1] if len(stack)>0 else -1)

    #size
    elif comm[0] == "size":
        print(len(stack))
    
    #empty
    elif comm[0] == "empty":
        print(1 if len(stack)==0 else 0)
    
    #pop
    elif comm[0] == "pop":
        print(stack.pop() if len(stack)>0 else -1)