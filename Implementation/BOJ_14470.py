#전자레인지
import sys
input=lambda :sys.stdin.readline().rstrip()
a=int(input()) # 원래 온도
b=int(input()) # 목표 온도
c=int(input()) # 0도 미만 일때 얼어있는 고기를 1도씨 씩 해동하는 시간
d=int(input()) # 0도 일때 얼어 있는 고기를 해동하는 데 걸리는 시간.
e=int(input()) # 얼어 있지 않은 고기를 1℃ 데우는 데 걸리는 시간
t=0
while a!=b:
    if a<0:
        t+=c*abs(a)
        a+=abs(a)
    else:
        if a==0:
            t+=d
            t+=b*e
            a=b
        else:
            t+=(b-a)*e
            a=b
print(t)