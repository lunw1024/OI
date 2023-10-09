t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    sa = sum(a)
    sb = sum(b)
    ans = sa
    l = [ans]
    i = 1
    while (i <= k):
        if i % 2 == 1:
            if b[-1] > a[0]:
                ans += b[-1] - a[0]
                a[0], b[-1] = b[-1], a[0]
                a.sort()
                b.sort()
        else:
            if a[-1] > b[0]:
                ans += b[0] - a[-1]
                b[0], a[-1] = a[-1], b[0]
                a.sort()
                b.sort()
        l.append(ans)
        # print("i = ", i)
        if len(l) >= 3 and l[-1] == l[-3]:
            i += max(0, (k - i) - (k - i) % 2)
        i += 1
    # if b[-1] >= a[-1]:
    #     ans = sa + (b[-1] - a[0]) * (k % 2 == 1)
    # else:
    #     ans = sa
    #     if b[-1] - a[0] > 0:
    #         ans += b[-1] - a[0]
    #         a[0], b[-1] = b[-1], a[0]
    #         a.sort()
    #         b.sort()
    #     ans += (b[0] - a[-1]) * (k % 2 == 0)
    print(ans)
    # print(l)