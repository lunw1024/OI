t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    idx, mx = 0, 0
    for i, x in enumerate(l):
        if abs(x) > mx:
            mx = abs(x)
            idx = i
    pos = l[idx] >= 0
    ops = [(i, idx + 1) for i in range(1, n+1)]
    if pos:
        ops.extend((i, i - 1) for i in range(2, n + 1))
    else:
        ops.extend((i - 1, i) for i in range(n, 1, -1))
    # print("case", _)
    print(len(ops))
    for op in ops:
        print(op[0], op[1])