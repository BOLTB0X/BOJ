#캠핑
import sys
input=lambda :sys.stdin.readline().rstrip()
i=1
while True:
    L, P, V = map(int, input().split()) #L:연속  P:사용가능 일수 V:휴가일수
    if P==L==V==0:
        break
    use=L*(V//P)
    use+=min(L,V%P) #만약 나머지가 L보다 커지면 안되므로
    print('Case {}: {}'.format(i,use))
    i+=1