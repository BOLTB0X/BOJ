import sys
input = sys.stdin.readline

T = int(input())
while T != 0:
    R,S = input().split()
    #정답
    result = ''
    
    for s in S:
        result += (s *int(R))
    
    #출력
    print(result)
    T -= 1
