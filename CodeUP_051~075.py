# 51번 정수 2개 입력받아 비교하기
a,b=map(int,input().split())
print(a!=b)

# 52번 정수 입력받아 참 거짓 평가하기
a=int(input())
print(bool(a))

# 53번 정수 입력받아 참 거짓 바꾸기 NOT
a=int(input())
print(not a)

# 54번 정수 입력받아 둘 다 참일 경우만 참 출력하기 AND
a,b=map(int,input().split())
print(bool(a) and bool(b))

# 55번 정수 입력받아 하나라도 참이면 참 출력하기 OR
a,b=map(int,input().split())
print(bool(a) or bool(b))

# 56번 정수 입력받아 참/거짓이 서로 다를 때에만 참 출력하기 XOR
n1,n2=map(int,input().split())
a=bool(n1)
b=bool(n2)
print(a and (not b) or (not a) and b)

# 57번 정수 입력받아 참/거짓이 서로 같을 때에만 참 출력하기 XNOR
a,b=map(int,input().split())
print((not bool(a)) and (not bool(b)) or bool(a) and bool(b))

# 58번 정수 입력받아 둘 다 거짓일 경우만 참 출력하기 NOR
a,b=map(int,input().split())
print(not (bool(a) or bool(b)))
print(not (bool(a) and bool(b))) #NAND

# 59번 비트단위로 NOT 하여 출력하기
a=int(input())
print(~a)

# 60번 비트단위로 AND 하여 출력하기
a,b=map(int,input().split())
print(a&b)

# 61번 비트단위로 OR 하여 출력하기
a,b=map(int,input().split())
print(a|b)

# 62번 비트단위로 XOR 하여 출력하기
a,b=map(int,input().split())
print(a^b)

# 63번 정수 2개 입력받아 큰 값 출력하기
a,b=map(int,input().split())
print(max(a,b))

# 64번 정수 3개 입력받아 작은 값 출력하기
a,b,c=map(int,input().split())
print(min(a,b,c))

# 65번 정수 3개 입력받아 짝수 값만 출력하기
a,b,c=map(int,input().split())
if a%2==0:
    print(a)
if b%2==0:
    print(b)
if c%2==0:
    print(c)

# 66번 정수 3개 입력받아 짝수 값만 출력하기
a,b,c=map(int,input().split())
if a%2 == 0:
    print('even')
elif a%2 != 0:
    print('odd')
if b%2 == 0:
    print('even')
elif b%2 != 0:
    print('odd')
if c%2 == 0:
    print('even')
elif c%2 != 0:
    print('odd')

# 67번 정수 1개 입력받아 분류하기
a=int(input())
if a<0:
    if a%2==0:
        print('A')
    else:
        print('B')
else:
    if a % 2 == 0:
        print('C')
    else:
        print('D')

# 68번 점수 입력받아 평가 출력하기
a = int(input())
if a >= 90:
    print('A')
else:
    if a>=70:
        print('B')
    else:
        if a>=40:
            print('C')
        else:
            print('D')

# 69번 평가 입력받아 다르게 출력하기
a = input()
if a == 'A':
    print('best!!!')
else:
    if a == 'B':
        print('good!!')
    else:
        if a == 'C':
            print('run!')
        else:
            if a == 'D':
                print('slowly~')
            else:
                print('what?')

# 70번 월 입력받아 계절 출력하기
a = int(input())
if a//3 == 1:
    print("spring")
elif a//3 == 2:
    print("summer")
elif a//3 == 3:
    print("fall")
else:
    print("winter")

# 71번 0 입력될 때까지 무한 출력하기
n=1
while n!=0:
    n = int(input())
    if n!=0:
        print(n)
        continue
    else:
        break

# 72번 정수 1개 입력받아 카운트다운 출력하기
n = int(input())
while n!=0:
    print(n)
    n-=1
    if n==0:
        break

# 73번 정수 1개 입력받아 카운트다운 출력하기
n = int(input())
while n!=0:
    n-=1
    print(n)
    if n==0:
        break

# 74번 문자 1개 입력받아 알파벳 출력하기
c = ord(input())
a = ord('a')
while a<=c :
  print(chr(a), end=' ')
  a += 1

# 75번 정수 1개 입력받아 그 수까지 출력하기
n = int(input())
a=0
while a<=n:
  print(a)
  a += 1