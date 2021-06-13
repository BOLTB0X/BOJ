#소인수분해
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