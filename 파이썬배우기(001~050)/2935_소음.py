import sys
input = sys.stdin.readline

a = int(input())
c = input()
b = int(input())

if c=='*':
    print(a*b)
else:
    print(a+b)
