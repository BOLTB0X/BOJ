#하얀 칸
graph=[]
cnt=0
for i in range(8):
    graph.append(list(input()))
for i in range(8):
    for j in range(8):
        if i%2==0 and j%2==0:
            if graph[i][j]=='F':
                cnt+=1
        elif i%2!=0 and j%2!=0:
            if graph[i][j]=='F':
                cnt+=1
print(cnt)