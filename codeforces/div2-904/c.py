T = int(input())
for t in range(T):
    n, m = map(int, input().split())
    segs = []
    a = []
    for i in range(n):
        l, r = map(int, input().split())
        segs.append((l, -1, i))
        segs.append((r, 1, i))
        a.append((l, r))
    segs.sort()
    ls = 0
    rs = 0
    cnt = 0
    ans = 0
    for x in segs:
        _, v, idx = x
        cnt += -v
        # print("cnt = ", cnt)
        if a[idx][0] == 1:
            ls += -v
        if a[idx][1] == m:
            rs += -v
        ans = max(ans, cnt - min(ls, rs))
    print(ans)