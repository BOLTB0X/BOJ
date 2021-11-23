import sys
input = sys.stdin.readline

S = int(input())
tot = 0

#그리드 알고리즘 이용
for i in range(1,S + 1):
    tot += i
    cnt = i
    
    #크다면
    if tot > S:
        tot -= i
        cnt = i - 1
        break
    
    #같다면
    elif tot == S:
        break

#출력
print(cnt)
