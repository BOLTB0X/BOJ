#세수 https://www.acmicpc.net/problem/10817
arr=list(map(int,input().split()))
arr.sort()
print(arr[1])

#다른풀이1 
a,b,c=map(int,input().split())
fir=sec=a
if fir<=b:
    fir=b
    if fir<=c:
        fir=c
        sec=b
    else:
        sec=max(a,c)
else:
    if fir<=c:
        fir=c
        sec=a
    else:
        sec=max(b,c)
print(sec)

#다른풀이2
a,b,c=map(int,input().split())
if a>=b:
    if a>=c:
        if b>=c:
            print(b)
        else:
            print(c)
    else:
        print(a)
else:
    if b>=c:
        if a>=c:
            print(a)
        else:
            print(c)
    else:
        print(b)