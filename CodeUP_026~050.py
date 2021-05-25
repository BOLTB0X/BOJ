# 26번
n1=float(input())
n2=float(input())
print(n1 + n2)

# 27번 16진수 소문자출력
n=int(input())
print('%x'%n)

# 28번 16진수 대문자출력
n=int(input())
print('%X'%n)

# 29번 소문자 16진수입력 8진수출력
n=int(input(),16)
print('%o'%n)

# 30번 영문자 1개 입력받아 10진수로 변환하기
n=ord(input()) #입력받은 문자를 10진수 유니코드 값으로 변환한 후, n에 저장한다.
print(n)

# 31번 정수 입력받아 유니코드 문자로 변환하기
n=int(input())
print(chr(n))  #c에 저장되어 있는 정수 값을 유니코드 문자(chracter)로 바꿔 출력한다.

# 32번 부호바꾸기
n=int(input())
print(-n)

# 33번 문자 1개 입력받아 다음 문자 출력하기
n=ord(input())
print(chr(n+1))

# 34번 정수 2개 입력받아 차 계산하기
a,b=map(int,input().split())
print(a-b)

# 35번 실수 2개 입력받아 곱 계산하기
a,b=map(float,input().split())
print(a*b)

# 36번 단어 여러 번 출력하기
a,b=input().split()
print(a*int(b))

# 37번 문장 여러 번 출력하기
n=int(input())
s=input()
print(s*n)

# 38번 정수 2개 입력받아 거듭제곱 계산하기
a,b=map(int,input().split())
print(a**b)

# 39번 실수 2개 입력받아 거듭제곱 계산하기
a,b=map(float,input().split())
print(a**b)

# 40번 정수 2개 입력받아 나눈 몫 계산하기
a,b=map(int,input().split())
print(a//b)

# 41번 정수 2개 입력받아 나눈 나머지 계산하기
a,b=map(int,input().split())
print(a%b)

# 42번 실수 1개 입력받아 소숫점이하 자리 변환하기
a=float(input())
print(round(a,2))

# 43번 실수 2개 입력받아 나눈 결과 계산하기
a,b=map(float,input().split())
f=a/b
print('%.3f'%f) #n은 출력할 실수 변수

# 44번 정수 2개 입력받아 자동 계산하기
a,b=map(int,input().split())
print(a+b)
print(a-b)
print(a*b)
print(a//b)
print(a%b)
print(round((a/b),2))

# 45번 정수 3개 입력받아 합과 평균 출력하기
a,b,c=map(int,input().split())
avg=round((a+b+c)/3,3)
print(a+b+c,'%.2f'%avg,sep=' ')

# 46번 정수 1개 입력받아 2배 곱해 출력하기
a=int(input())
print(a*2)

# 47번 2의 거듭제곱 배로 곱해 출력하기
a,b=map(int,input().split())
print(a*2**b)

# 48번 정수 2개 입력받아 비교하기
a,b=map(int,input().split())
print(a<b)

# 49번 정수 2개 입력받아 비교하기
a,b=map(int,input().split())
print(a==b)

# 50번 정수 2개 입력받아 비교하기
a,b=map(int,input().split())
print(a<=b)