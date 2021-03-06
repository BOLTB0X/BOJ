import sys
input = sys.stdin.readline

#최대공약수
def gcd(a,b):
    if a%b == 0:
        return b
    else:
        return gcd(b,a%b)

#최소공배수
def lcm(a,b):
    return (a*b) // gcd(a,b)

a,b = map(int,input().split())
print(gcd(a,b))
print(lcm(a,b))