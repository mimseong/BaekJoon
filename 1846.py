def main():
    n = int(input())

    if n == 3:
        print(-1)
        return

    if n % 2 == 1:
        print(n // 2 + 2)

        for i in range(n, n // 2 + 2, -1):
            print(i)

        print(1)

        for i in range(n // 2 + 1, 1, -1):
            print(i)

        return

    print(2)
    print(1)
    for i in range(n, 2, -1):
        print(i)


if __name__ == "__main__":
    main()
