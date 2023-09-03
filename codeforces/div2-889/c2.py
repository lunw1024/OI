t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    idx, mx = 0, 0
    poscnt, negcnt = 0, 0
    for i, x in enumerate(l):
        if abs(x) > mx:
            mx = abs(x)
            idx = i
        poscnt += x > 0
        negcnt += x < 0
    if mx == 0:
        print(0)
        continue
    pos = l[idx] > 0
    ops = []
    if pos and negcnt > 12:
        # find neg
        negidx = 0
        for i in range(n):
            if l[i] < 0:
                negidx = i
                break
        # make it big
        ops.extend((negidx + 1, negidx + 1) for i in range(5))
        pos = False
        idx = negidx
    if not pos and poscnt > 12:
        # find pos
        posidx = i
        for i in range(n):
            if l[i] > 0:
                posidx = i
                break
        ops.extend((posidx + 1, posidx + 1) for i in range(5))
        pos = True
        idx = posidx

    if pos:
        ops.extend((i, idx + 1) for i in range(1, n+1) if l[i-1] < 0)
        ops.extend((i, i - 1) for i in range(2, n + 1))
    else:
        ops.extend((i, idx + 1) for i in range(1, n+1) if l[i-1] > 0)
        ops.extend((i - 1, i) for i in range(n, 1, -1))

    # print("used", len(ops), "ops")
    # for i, j in ops:
    #     l[i-1] += l[j-1]
    # print(l)
    print(len(ops))
    for i, j in ops:
        print(i, j)
    #