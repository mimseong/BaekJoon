import sys

input = sys.stdin.readline

N = int(input().rstrip())
nums = [[], []]  # nums[0]: 짝수 좌표합, nums[1]: 홀수 좌표합

for i in range(1, N + 1):
    x, y = map(int, input().rstrip().split())
    nums[(x + y) % 2].append(i)

if len(nums[0]) == 0 or len(nums[1]) == 0:  # 홀수 또는 짝수가 없다면
    print("NO")
else:
    print("YES")
    for group in nums:
        for num in group:
            print(num, end=" ")
