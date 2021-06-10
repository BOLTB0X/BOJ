s1=int(input())
s2=int(input())
s3=int(input())

if (s1+s2+s3)==180:
    if s1!=s2!=s3:
        print('Scalene')
    elif s1!=s2==s3 or s1==s2!=s3 or s1==s3!=s2:
        print('Isosceles')
    elif s1==60 and s2==60 and s3==60:
        print("Equilateral")
else:
    print('Error')