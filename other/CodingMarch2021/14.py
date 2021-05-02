from collections import Counter
N = int(input())
arr = list(map(int, input().split()))
MOD = int(1e9) + 7
o, e = filter(lambda i: i % 2 == 1, arr), filter(lambda i: i % 2 == 0, arr)
o, e = Counter(o), Counter(e)

os, es = sum(o.values()) % MOD, sum(e.values()) % MOD
ans = 0
ans += es % MOD # e
ans %= MOD
# oe/eo
ans += es * os % MOD * 2 % MOD
ans %= MOD
# oeo
for k, v in o.items():
    ans += v * (os - 1) % MOD * es % MOD
    ans %= MOD
# eoe
for k, v in e.items():
    ans += v * (es - 1) % MOD * os % MOD
    ans %= MOD
print(ans)