from sys import stdin
#입력 
input = stdin.readline

#이진탐색
def Binary_Search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == target:
            return 1
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return 0

#카드 리스트
n = int(input())
nums = list(map(int,input().split()))

#오름차순 정렬
nums.sort()
m = int(input())
targets = list(map(int,input().split()))
for i in range(m):
    print(Binary_Search(nums,targets[i],0,n-1))