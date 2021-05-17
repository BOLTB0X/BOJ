T = int(input())
for tc in range(1, 1 + T):
    alp= list(str(input()))
    stack = []
    for i in alp:
        if i not in stack:
            stack.append(i)
        else:
            stack.remove(i)
    stack.sort()
    print('#{}'.format(tc), end=' ')
    if len(stack) != 0:
        for k in stack:
            print(k, end='')
        print()
    else:
        print('Good')