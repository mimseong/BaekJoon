def main():
    n = int(input())
    lst = list(map(int, input().split()))

    lst.sort(reverse=True)

    if n == 1:
        if lst[0] > 1440:
            lst[0] = -1
        print(lst[0])
        return

    ans = 0
    for _ in range(100):
        # print(lst)
        if lst[1] == 0:
            break

        lst[0] -= lst[1]
        ans += lst[1]
        lst[1] = 0

        lst.sort(reverse=True)

    ans += lst[0]

    if ans > 1440:
        ans = -1

    print(ans)


if __name__ == "__main__":
    main()
