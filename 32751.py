def main():
    n = int(input())
    a, b, c, d = list(map(int, input().split()))
    s = input()

    if not (s[0] == s[-1] and s[0] == 'a'):
        print("No")
        return

    for i in range(0, len(s)):
        if 0 < i and s[i] == s[i-1]:
            print("No")
            return

        if s[i] == 'a':
            a -= 1
        elif s[i] == 'b':
            b -= 1
        elif s[i] == 'c':
            c -= 1
        else:
            d -= 1

        if a < 0 or b < 0 or c < 0 or d < 0:
            print("No")
            return

    print("Yes")


if __name__ == "__main__":
  main()
