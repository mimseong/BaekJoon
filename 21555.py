def main():
    N, M = map(int, input().split())

    v = list(map(int, input().split()))
    u = list(map(int, input().split()))

    dp = [[0] * 2 for _ in range(N)]
    dp[0][0] = v[0]
    dp[0][1] = u[0]

    for i in range(1, N):
        dp[i][0] = min(dp[i-1][0], dp[i-1][1] + M) + v[i]
        dp[i][1] = min(dp[i-1][1], dp[i-1][0] + M) + u[i]

    ans = min(dp[N-1][0], dp[N-1][1])
    print(ans)

if __name__ == "__main__":
    main()

