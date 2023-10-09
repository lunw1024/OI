n = int(input())
a = list(map(int, input().split()))
INF = int(1e9)
dp = [[INF] * 2 for _ in range(n + 1)]
dp[0][0] = 0
for i in range(1, n+1):
    if a[i-1] == 0:
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][0] + 1)
    elif a[i-1] == 1:
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1)
        dp[i][0] = dp[i - 2][0] + 1
        if i >= 2 and a[i - 2] > 0:
            dp[i][0] = min(dp[i][0], dp[i - 1][0])
    else:
        dp[i][1] = min(dp[i - 1][1], (dp[i - 2][0] if i >= 2 else 0) + 1)
        if i >= 2 and a[i - 2] > 0:
            dp[i][1] = min(dp[i][1], dp[i - 1][0])
    dp[i][0] = min(dp[i][0], dp[i][1])
print(dp[n][0])
# print(dp)
# 