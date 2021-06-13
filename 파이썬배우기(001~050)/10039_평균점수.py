#평균 점수 https://www.acmicpc.net/problem/10039
tot=0
for _ in range(5):
    a=int(input())
    if a<=40:
        a=40
    tot+=a
print(tot//5)