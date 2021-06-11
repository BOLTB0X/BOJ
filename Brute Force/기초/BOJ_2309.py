heights=[]
for _ in range(9):
    heights.append(int(input()))
for i in range(len(heights)-1):
    for j in range(i+1,len(heights)):
        if (sum(heights)-heights[i]-heights[j]==100):
            check=[heights[i],heights[j]]
            break
heights.remove(check[0])
heights.remove(check[1])
heights.sort()
for h in heights:
    print(h)