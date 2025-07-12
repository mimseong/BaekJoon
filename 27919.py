
def main():
    s = input()

    dp = 0
    uc = 0
    for si in s:
        if si == "U" or si == "C":
            uc += 1
        elif si == "D" or si == "P":
            dp += 1

    ans = ""
    if uc > (dp + 1) / 2:
        ans += "U"
    if dp > 0:
        ans += "DP"
    print(ans)

if __name__ == "__main__":
    main()

