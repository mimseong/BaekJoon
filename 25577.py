def minimum_swaps(N, arr):
    pos = {value: index for index, value in enumerate(arr)}
    sorted_arr = sorted(arr)
    visited = [False] * N
    swaps = 0

    for i in range(N):
        if visited[i] or pos[sorted_arr[i]] == i:
            continue

        cycle_length = 0
        x = i
        while not visited[x]:
            visited[x] = True
            x = pos[sorted_arr[x]]
            cycle_length += 1

        if cycle_length > 0:
            swaps += cycle_length - 1

    return swaps


def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(minimum_swaps(N, arr))


if __name__ == "__main__":
    main()
