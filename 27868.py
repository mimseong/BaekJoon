import sys

input = sys.stdin.readline

n, s = map(int, input().split())
a_list = list(map(int, input().split()))
command = input().rstrip()

print(command[::-1])
