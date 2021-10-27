#입출력
from sys import stdin
#입력 
input = stdin.readline

heights = []
#난쟁이들 키 입력
for i in range(9):
    heights.append(int(input()))

#난쟁이들이 아닌 놈들 탐색
for i in range(9):
    for j in range(i+1,9):
        #발견 조건
        if sum(heights) - heights[i] - heights[j] == 100:
            #0처리
            heights[i]=0
            heights[j]=0
            break

#오름차순 정렬
heights.sort()

for height in heights:
    #지워진 난쟁이들 패스
    if height == 0:
        continue
    print(height)