#동전
n=int(input())
cnt=0
cointype=[500,100,50,10,5,1]
rest_coin=1000-n
for coin in cointype:
    cnt+=rest_coin//coin
    rest_coin%=coin
print(cnt)