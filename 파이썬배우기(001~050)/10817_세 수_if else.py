#분기문이용
import sys
input = sys.stdin.readline

A,B,C = map(int,input().split())

if A >= B:
    #A가 제일 크다면
    if A >= C:
        if B >= C:
            print(B)
        else:
            print(C)
    #C가 더 크다면
    else:
        print(A)
else:
    #B가 제일 크다면
    if B >= C:
        if A >= C:
            print(A)
        else:
            print(C)
    #C가 크다면
    else:
        print(B)