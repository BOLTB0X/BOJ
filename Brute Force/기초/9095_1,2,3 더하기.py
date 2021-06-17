def check_function(n):
    if n==1:
        return 1
    elif n==2:
        return 2
    elif n==3:
        return 4
    else:
        return check_function(n-1) + check_function(n-2)+ check_function(n-3)
T=int(input())
for _ in range(T):
    n=int(input())
    print(check_function(n))