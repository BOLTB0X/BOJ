cards=[i for i in range(21)]
for _ in range(10):
    a,b=map(int,input().split())
    for j in range((b-a+1)//2):
        temp=cards[b-j]
        cards[b-j]=cards[a+j]
        cards[a+j]=temp
print(*cards[1:])