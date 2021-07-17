n=input()
nums=list(input().split())
answer=0
for num in nums:
    if int(num)%1==int(n): #일의 자리가 같다면
        answer+=1
print(answer)
