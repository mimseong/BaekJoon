def main():
    n = int(input())

    dict = {}
    for i in range(n):
        s = input()

        dot_pos = s.find(".")
        extension = s[dot_pos + 1 :]

        if dict.get(extension) is None:
            dict[extension] = 1
        else:
            dict[extension] += 1

    keys = []
    for key in dict:
        keys.append(key)

    keys.sort()

    for key in keys:
        print(f"{key} {dict[key]}")


if __name__ == "__main__":
    main()
