#운동
import sys
input=lambda :sys.stdin.readline().rstrip()
N,m,M,T,R=map(int,input().split()) #N은 운동시간, m은 초기맥박
e_m=m #운동 맥박
result=0 #T는 증가맥박 M은 맥박제한선 R은 휴식 후 감소맥박
hour=0
if M-m<T:
    print(-1)
    exit()
while N!=0:
    if e_m+T<=M:
        e_m+=T
        N-=1
    else:
        e_m-=R
        if e_m<m:
            e_m=m;
    result+=1
print(result)
