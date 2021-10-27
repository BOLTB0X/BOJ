#입출력
from sys import stdin
#입력 
input = stdin.readline

n=int(input())
nums=list(map(int,input().split()))
cnt=0

#순회 시작
for num in nums:
    #1인 경우
    if num == 1:
        pass
    
    #2인 경우
    elif num == 2:
        cnt += 1

    #그 외
    else:
        for i in range(2,num):
            if num%i == 0:
                break
            elif i == num-1:
                cnt += 1
print(cnt)