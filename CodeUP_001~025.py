#1번 출력
print("Hello")

#2번 출력
print("Hello World")

#3번 출력
print("Hello")
print("World")

#4번 출력
print("\'Hello\'")

#5번 출력
print("\"Hello World\"")

#6번 출력
print("\"!@#$%^&*()\'")

#7번 출력
print("\"C:\\Download\\\'hello\'.py\"")

#8번 출력
print("print(\"Hello\\nWorld\")")

#9번 입출력
c=input()
print(c)

#10번 입출력
n=int(input())
print(n)

#11번 입출력
f=float(input())
print(f)

#12번 입출력
a=int(input())
b=int(input())
print(a)
print(b)

#13번 입출력
a=input()
b=input()
print(b)
print(a)

#14번 입출력
f=float(input())
print(f)
print(f)
print(f)
# for _ in range(3):
#     print(f)

#15번 입출력
a,b=input().split()
print(a)
print(b)

#16번 입출력
a,b=input().split()
print(b,a)

#17 입출력
s=input()
print(s,s,s)

# 18번
h, m = input().split(':')
print(h, m, sep=':')

# 19번
y,m,d= input().split('.')
print(d,m,y,sep='-')

# 20번
a,b=input().split('-')
print(a+b)

# 21번
s=input()
for i in range(len(s)):
    print(s[i])

# 22번
s=input()
print(s[0:2],s[2:4],s[4:6])

# 23번
h,m,s=input().split(':')
print(m)

# 24번
s,c=input().split()
print(s+c)

# 25번
n1,n2=map(int,input().split())
print(n1 + n2)