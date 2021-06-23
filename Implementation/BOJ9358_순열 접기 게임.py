from collections import deque
    
t=int(input())
for j in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    dque=deque()
    for i in range(n):
        dque.append(arr[i])
    while True:
        if len(dque)==2:
            break
        new_dque=deque()
        while dque:
            new_dque.append(dque[0]+dque[len(dque)-1])
            dque.popleft()
            if dque: dque.pop()
        while new_dque:
            dque.append(new_dque[0])
            new_dque.popleft();
    print('Case #{}: {}'.format(j+1,'Alice' if dque[0]>dque[1] else 'Bob'))