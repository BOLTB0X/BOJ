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
    
n = int(input())
cards = list(map(int,input().split()))

m = int(input())
check = list(map(int,input().split()))

#이진탐색을 위한 오름차순
cards.sort()

#정답 결과
result = []

for i in range(m):
    result.append(Binary_Search(cards,check[i],0,n-1))

for r in result:
    print(r, end= " ")