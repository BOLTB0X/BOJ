import sys
input = sys.stdin.readline

a,b,c=map(int,input().split())
#초단위로 입력받음
d=int(input()) 
#d는 60을 넘으면 안되므로
c+=d%60 
#b에 60의 몫을 더해줌
b+=d//60 

while a >= 24 or b >= 60 or c >= 60:
    if c >= 60:
        b += 1
        c -= 60
    if b >= 60:
        a += 1
        b -= 60
    if a >= 24:
        a -= 24
        
print(a,b,c)
