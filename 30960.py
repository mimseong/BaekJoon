import sys

input = sys.stdin.readline

N = int(input().strip())
arr = list(map(int, input().strip().split()))

arr.sort()

sum_value = arr[2] - arr[0]
for i in range(4, N, 2):
    sum_value += arr[i] - arr[i - 1]

ans = sum_value
for i in range(2, N - 1, 2):
    sum_value -= arr[i] - arr[i - 2]
    sum_value -= arr[i + 2] - arr[i + 1]
    sum_value += arr[i - 1] - arr[i - 2]
    sum_value += arr[i + 2] - arr[i]

    ans = min(ans, sum_value)

print(ans)
