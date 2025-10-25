from math import sqrt


def main():
    n = int(input())

    lst = []
    for _ in range(n):
        x, y = list(map(int, input().split()))
        lst.append({"x": x, "y": y})

    min_x, min_y = 987654321, 987654321
    min_len = 987654321

    sx, sy = 0, 0
    for i in range(len(lst)):
        sx = sx + lst[i]["x"]
        sy = sy + lst[i]["y"]

    print(sx, sy)

    for i in range(len(lst)):
        sx, sy = 0, 0
        for j in range(len(lst)):
            if i == j:
                continue
            sx = sx + lst[j]["x"]
            sy = sy + lst[j]["y"]

        if sx * sx + sy * sy < min_len:
            min_len = sx * sx + sy * sy

    print(f"{sqrt(min_len):.2f}")


if __name__ == "__main__":
    main()
