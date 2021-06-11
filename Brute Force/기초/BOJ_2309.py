heights=[]
for _ in range(9):
    heights.append(int(input())) 
for i in range(len(heights)-1): #두 놈을 체크해야 하므로 i는 앞놈 이므로
    for j in range(i+1,len(heights)): #j는 뒷놈 이므로
        if (sum(heights)-heights[i]-heights[j]==100): #조건 
            check=[heights[i],heights[j]] #여기서 한번에 제거를 해버리면 인덱스가 변경되므로 check리스트에 담는다.
            break
heights.remove(check[0]) #제거
heights.remove(check[1])
heights.sort() #정렬
for h in heights:
    print(h)
