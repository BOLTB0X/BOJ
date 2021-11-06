#입출력
from sys import stdin
#입력 
input = stdin.readline

n=int(input())
nums=[]

for i in range(n):
    nums.append(int(input()))

#정렬
nums.sort()

#출력
for num in nums:
    print(num)