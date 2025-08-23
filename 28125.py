dict = {
    "\\\\'": "w",
    "\\'": "v",
    "@": "a",
    "[": "c",
    "!": "i",
    ";": "j",
    "^": "n",
    "0": "o",
    "7": "t",
}


def solve():
    s = input()

    count = 0
    sorted_keys = sorted(dict.keys(), key=len, reverse=True)

    for d in sorted_keys:
        count += s.count(d)
        s = s.replace(d, dict[d])

    if count >= (len(s) / 2):
        print("I don't understand")
        return

    print(s)
    return


def main():
    n = int(input())

    for _ in range(n):
        solve()


if __name__ == "__main__":
    main()
