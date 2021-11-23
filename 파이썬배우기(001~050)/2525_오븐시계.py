import sys
input = sys.stdin.readline

#현재 시간
a,b=map(int,input().split())
#소요시간
c=int(input())

#분이 60을 넘어가게 되면
if 60 <= (b+c):
    #더해줌
    a += (b+c)//60
    #만약 23시를 넘게 되면
    if a > 23:
        a -= 24
    b = (b+c)%60
    
    #시간 출력
    print(a,b)

#그 외
else:
    print(a,b+c)
