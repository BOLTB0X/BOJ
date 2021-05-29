# 76번 정수 1개 입력받아 그 수까지 출력하기
n = int(input())
for i in range(n+1):
    print(i)

# 77번 짝수 합 구하기
n = int(input())
s=0
for i in range(n+1):
    if i%2 == 0:
        s+=i
print(s)

# 78번 원하는 문자가 입력될 때까지 반복 출력하기
n=1
while n!=0:
    n=input()
    print(n)
    if n == 'q':
        break

# 79번 언제까지 더해야 할까?
a,b=map(int,input().split())
for i in range(a):
    for j in range(b):
        print(i+1,j+1)

# 80번 주사위 2개 던지기
a,b=map(int,input().split())
for i in range(a):
    for j in range(b):
        print(i+1,j+1)

# 81번 16진수 구구단
a=int(input(),16) #16진수 입력
for i in range(1,16):
    print('%X'%a+'*%X'%i+'=%X'%(a*i))

# 82번 3 6 9 게임의 왕이 되자
a=int(input())
for i in range(1,a+1):
    str_a=str(i)
    if ('3' in str_a) | ('6' in str_a) | ('9' in str_a):
        print('X',end=' ')
    else:
        print(str_a,end=' ')

# 83번 빛 섞어 색 만들기
r,g,b = map(int,input().split())
cnt=0;
for i in range(r):
    for j in range(g):
        for k in range(b):
            print('%d %d %d' %(i,j,k))
            cnt+=1
print(cnt)

# 84번 소리 파일 저장용량 계산하기
h,b,c,s = map(int,input().split())
s=float((h*b*c*s)/8/1024/1024)
print('%.1f'%s,'MB')

# 85번 파일 저장용량 계산하기
w,h,b = map(int,input().split())
s=float((w*h*b)/8/1024/1024)
print('%.2f'%s,'MB')

# 86번 3의배수 통과
n=int(input())
s=0
for i in range(1,n+1):
    s+=i
    if s>=n:
        break
print(s)

# 87 거기까지! 이제 그만~
n=int(input())
for i in range(1,n+1):
    if i%3==0:
        continue
    print(i,end=' ')

# 88번 등차수열
a,d,n = map(int,input().split())
s=a
for i in range(1,n):
    s+=d
print(s)

# 89번 등비수열
a,r,n = map(int,input().split())
s=a
for i in range(1,n):
    s*=r
print(s)

# 90번 수 나열하기
a,m,d,n = map(int,input().split())
s=a
for i in range(1,n):
     s*=m
     s+=d
print(s)

# 91번 수 나열하기
a,b,c = map(int,input().split())
d = 1
while d%a != 0 or d%b != 0 or d%c != 0:
     d += 1
print(d)

# 92번 이상한 출석 부르기
n = int(input())
data = list(map(int,input().split()))
d=[]
for i in range(24):
     d.append(0)
for j in range(n):
     d[data[j]]+=1
for k in range(1,24):
     print(d[k],end=' ')

# 93번 이상한 출석 부르기 거꾸로
n = int(input())
data = list(map(int,input().split()))
data.reverse()
for i in range(n):
     print(data[i],end=' ')

# 94번 이상한 출석 부르기 가장 작은 수
n = int(input())
data = list(map(int,input().split()))
data.sort()
print(data[0])

# 95번 바둑판에 흰 돌 놓기
d=[]
for i in range(20):
     d.append([])
     for j in range(20):
          d[i].append(0)

n=int(input())
for i in range(n):
     x,y=map(int,input().split())
     d[int(x)][int(y)]=1
for i in range(1,20):
     for j in range(1,20):
          print(d[i][j],end=' ')
     print()

# 96번 바둑알 십자 뒤집기
d = [[] * 19 for _ in range(19)]
for i in range(19):
     d[i] = list(map(int, input().split()))

n = int(input())

for i in range(n):
     x, y = map(int, input().split())

     for j in range(19):
          if (d[x - 1][j] == 1):
               d[x - 1][j] = 0
          else:
               d[x - 1][j] = 1

     for j in range(19):
          if (d[j][y - 1] == 1):
               d[j][y - 1] = 0
          else:
               d[j][y - 1] = 1

for i in range(19):
     for j in range(19):
          print(d[i][j], end=' ')
     print()

# 97번 설탕과자 뽑기
h,w=map(int,input().split())
li = [[0] * w for _ in range(h)]
n=int(input())
for i in range(n):
     l,d,x,y=map(int,input().split())
     if (d == 0):
          for j in range(l):
               li[x - 1][y - 1 + j] = 1
     else:
          for j in range(l):
               li[x - 1 + j][y - 1] = 1

for i in range(h):
     for j in range(w):
          print(li[i][j], end=' ')
     print()

##98번 성실한 개미
m = [[] * 10 for _ in range(10)]
for i in range(10):
      m[i] = list(map(int, input().split()))
x=1
y=1
m[x][y]=9

while True:
    if(m[x][y]==2):
        m[x][y]=9
        break
    if(m[x][y+1]!=1):
        m[x][y]=9
        y+=1
    else:
        if(m[x+1][y]!=1):
            m[x][y]=9
            x+=1
        else:
          m[x][y]=9
          break

for i in range(10):
    for j in range(10):
        print(m[i][j],end=' ')
    print()