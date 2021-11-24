import sys
input = sys.stdin.readline

#피보나치 수열
def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

#출력
print(fibonacci(int(input())))