#파이썬 내장함수 lower, upper
from bisect import bisect_left, bisect_right
from sys import stdin
#입력 
input = stdin.readline

n = int(input())
cards = list(map(int,input().split()))
m = int(input())
targets = list(map(int,input().split()))

#오름차순 정렬
cards.sort()

#각 타겟들을 순회
for i in range(len(targets)):
    right_idx = bisect_right(cards,targets[i])
    left_idx = bisect_left(cards,targets[i])
    print(right_idx - left_idx, end = ' ')
print() 