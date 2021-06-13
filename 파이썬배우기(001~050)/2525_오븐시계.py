# 오븐시계 https://www.acmicpc.net/problem/2525
a,b=map(int,input().split()) #현재 시간
c=int(input()) #소요시간
if (b+c)>=60: #만약 60분을 넘게되면
    a+=(b+c)//60 #시간+
    if a>23: #시간을 23이내로 표기해야므로
        a-=24
    b=(b+c)%60 #b도 60을 넘으면 안되므로
    print(a,b)
else:
    print(a,b+c)

##다른 풀이
a+=c//60
b+=c%60
if b>=60:
    a+=1
    b-=60
if a>=24:
    a-=24
print(a,b)