n=input()
nums=list(input().split())
answer=0
for num in nums:
    if int(num)%1==int(n):
        answer+=1
print(answer)