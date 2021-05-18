woods=list(map(int,input().split()))
for i in range(5):
    for j in range(1,5):
        if woods[j]<woods[j-1]:
            woods[j],woods[j-1]=woods[j-1],woods[j]
            print(*woods)