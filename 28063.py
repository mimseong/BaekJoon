n = int(input())
x, y = map(int, input().split())

if n == 1:
    print(0)
else:
    if (x, y) in ((1, 1), (n, n), (1, n), (n, 1)):
        print(2)
    elif x == 1 or x == n or y == 1 or y == n:
        print(3)
    else:
        print(4)
