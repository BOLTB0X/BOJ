from sys import stdin
#입력 
input = stdin.readline

n = int(input())
cards = list(map(int,input().split()))
m = int(input())
targets = list(map(int,input().split()))

#결과용 
hashmap = {}

#먼저 해쉬테이블을 이용하여 카드들의 수 카운트
for card in cards:
    if card in hashmap:
        hashmap[card] += 1
    else:
        hashmap[card] = 1

#출력   
print(' '.join(str(hashmap[target]) if target in hashmap else '0' for target in targets))