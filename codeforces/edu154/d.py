t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    suf = [0] * n
    for i in range(n - 2, -1, -1):
        suf[i] = suf[i + 1] + int(a[i] >= a[i + 1])
    up, down = 0, 0
    ans = int(1e9)
    for i in range(n):
        cost = suf[i] + int(i > 0) + up
        if i > 0:
            up += a[i - 1] <= a[i]
        ans = min(ans, cost)
    print(ans)