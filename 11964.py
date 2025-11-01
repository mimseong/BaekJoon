from collections import deque


def max_fullness(T, A, B):
    dp = [[False] * 2 for _ in range(T + 1)]
    dp[0][0] = True

    # 0: 물 안 마심, 1: 물 마심
    q = deque([(0, 0)])

    while q:
        fullness, used_water = q.popleft()

        # 오렌지
        if fullness + A <= T and not dp[fullness + A][used_water]:
            dp[fullness + A][used_water] = True
            q.append((fullness + A, used_water))

        # 레몬
        if fullness + B <= T and not dp[fullness + B][used_water]:
            dp[fullness + B][used_water] = True
            q.append((fullness + B, used_water))

        # 물
        if used_water == 0:
            reduced = fullness // 2
            if not dp[reduced][1]:
                dp[reduced][1] = True
                q.append((reduced, 1))

    max_val = 0
    for f in range(T + 1):
        if dp[f][0] or dp[f][1]:
            max_val = f

    return max_val


if __name__ == "__main__":
    T, A, B = map(int, input().split())
    print(max_fullness(T, A, B))
