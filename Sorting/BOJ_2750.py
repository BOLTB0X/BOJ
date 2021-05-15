import sys
input=lambda :sys.stdin.readline().rstrip()
n=int(input())
nums=[]
for i in range(n):
    nums.append(int(input()))
nums.sort()
for j in nums:
    print(j)