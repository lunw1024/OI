T = int(input())
for _ in range(T):
    m, k, a1, ak = map(int, input().split())
    m -= min(ak, m // k) * k
    m -= min(m, a1)
    ans = m // k + m % k
    if a1 + m % k >= k:
        ans = min(ans, ans - m % k + 1)
    print(ans)