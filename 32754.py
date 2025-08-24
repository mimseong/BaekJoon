import math
import sys

input = sys.stdin.readline
data = input().rstrip()


def main():
    n, r1 = list(map(int, input().split()))
    ans = 0

    for _ in range(n):
        x1, y1, x2, y2, x3, y3, x4, y4 = list(map(int, input().split()))

        center_x = (x1 + x2 + x3 + x4) / 4
        center_y = (y1 + y2 + y3 + y4) / 4

        r2 = math.sqrt((x1 - center_x) ** 2 + (y1 - center_y) ** 2)

        distance = math.sqrt(center_x**2 + center_y**2)

        if distance <= r1 + r2:
            ans += 1

    print(ans)


if __name__ == "__main__":
    main()
