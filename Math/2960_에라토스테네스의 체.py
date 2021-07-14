def getPrimaryNum_Eratos(number,target): 
    number_visited = [True] * (number + 1) 
    cnt=0
    for i in range(2, number + 1): 
        for j in range(i, number+1, i): #배수들을 지워준다
            if number_visited[j]:
                number_visited[j] = False 
                cnt+=1

                if cnt==target:
                    return j

n,k=map(int,input().split())
print(getPrimaryNum_Eratos(n,k))