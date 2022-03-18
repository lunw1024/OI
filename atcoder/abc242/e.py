import math

N, M, B, W = map(int, input().split())
MOD = 998244353
fact = [1] * (N * M + 1)
inv = [1] * (N * M + 1)
finv = [1] * (N * M + 1)
for i in range(2, N * M + 1):
    fact[i] = fact[i - 1] * i % MOD
    inv[i] = -(MOD // i) * inv[MOD % i] % MOD
    finv[i] = finv[i - 1] * inv[i] % MOD


def binom(n, k):
    return 0 if n < 0 or k < 0 or n < k else fact[n] * finv[k] % MOD * finv[n - k] % MOD

dpb, dpw = [[0] * (M + 1) for _ in range(N + 1)], [[0] * (M + 1) for _ in range(N + 1)]

def calc(dp, k):
    for n in range(1, N + 1):
        for m in range(1, M + 1):
            dp[n][m] = binom(n * m, k)
            for i in range(1, n + 1):
                for j in range(1, m + 1):
                    if i == n and j == m:
                        continue
                    dp[n][m] -= binom(n, i) * binom(m, j) % MOD * dp[i][j] % MOD
                    dp[n][m] %= MOD

calc(dpb, B)
calc(dpw, W)

ans = 0
for i in range(1, N + 1):
    for j in range(1, N - i + 1):
        for k in range(1, M + 1):
            for l in range(1, M - k + 1):
                ans += binom(N, i) * binom(N - i, j) % MOD * binom(M, k) % MOD * binom(M - k, l) % MOD * dpb[i][k] % MOD * dpw[j][l] % MOD
                ans %= MOD

print(ans)
