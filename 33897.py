# 입력
# 9
# 6 7 8 9 3 4 5 1 2

# 출력
# 3 4


def main():
    n = int(input())
    l = list(map(int, input().split()))

    max_length = 1
    current_length = 1
    cut_count = 1

    for i in range(1, n):
        if l[i - 1] <= l[i]:
            current_length += 1
        else:
            max_length = max(max_length, current_length)
            current_length = 1
            cut_count += 1

    max_length = max(max_length, current_length)

    print(cut_count, max_length)


if __name__ == "__main__":
    main()
