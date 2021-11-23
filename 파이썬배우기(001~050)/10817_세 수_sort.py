#정렬이용
import sys
input = sys.stdin.readline

nums = list(map(int,input().split()))

#오름차순 정렬
nums.sort()
print(nums[1])