import sys
import math
input = sys.stdin.readline

#소수판별
def is_prime(n):
    if n == 0 or n == 1:
        return False
    
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True

M = int(input())
N = int(input())
result = []

for num in range(M,N+1):
    if is_prime(num) == True:
        result.append(num)

if len(result) == 0:
    print(-1)
else:
    print(sum(result))
    print(result[0])