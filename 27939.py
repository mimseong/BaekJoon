import sys

input = sys.stdin.readline


n = int(input().rstrip())
v1 = list(input().rstrip().split())
m, k = map(int, input().split())

all_white = 0

for i in range(m):
    v2 = list(input().rstrip().split())

    is_all_white = True
    for idx in v2:
        if v1[int(idx) - 1] == 'P':
            is_all_white = False

    if is_all_white:
        all_white += 1

if all_white >= 1:
    print("W\n")
else:
    print("P\n")

