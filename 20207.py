def main():
    n = int(input())
    lst = [0] * 366

    for _ in range(n):
        s, e = list(map(int, input().split()))
        for i in range(s, e + 1):
            lst[i] += 1

    r = 0
    c = 0
    ans = 0
    for i in range(366):
        if lst[i] > 0:
            r = max(r, lst[i])
            c += 1
        else:
            ans += r * c
            r = 0
            c = 0
    ans += r * c

    print(ans)


if __name__ == "__main__":
    main()
