t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    a.append(a[0] + n)
    segs = []
    for i in range(0, m):
        segs.append(a[i + 1] - a[i] - 1)
    segs.sort(reverse=True)
    t = 0
    ans = 0
    # print(segs)
    for seg in segs:
        ans += max(0, 1 if seg - 2 * t == 1 else seg - 2 * t - 1)
        t += 2
    print(n - ans)