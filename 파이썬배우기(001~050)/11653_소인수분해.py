import sys
input = sys.stdin.readline

n=int(input())
d=2
answer=[]

while n>1:
    if n%d==0:
        n//=d
        answer.append(d)
    else:
        d+=1
print(*answer)
