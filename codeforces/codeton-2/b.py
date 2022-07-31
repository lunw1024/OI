t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    mi, mx = int(1e10), -int(1e10)
    ans = 0
    for y in a:
        mi = min(mi, y)
        mx = max(mx, y)
        # print("at", y, ",", mx, mi)
        if mx - mi > 2 * x:
            ans += 1
            # print("add to ans at", y)
            mi, mx = y, y
    print(ans)
