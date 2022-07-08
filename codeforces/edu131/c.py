t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    arr = map(int, input().split())
    cnt = [0] * n
    for x in arr:
        cnt[x - 1] += 1
    ans = 1
    while ans // 2 * n < m:
        work = m
        for k, v in enumerate(cnt):
            work -= min(v, ans)
            time = ans - min(v, ans)
            work -= time // 2
        if work <= 0:
            break
        ans += 1
    print(ans)