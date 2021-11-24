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

n = int(input())
nums = list(map(int,input().split()))
cnt = 0

for num in nums:
    if is_prime(num):
        cnt += 1
print(cnt)