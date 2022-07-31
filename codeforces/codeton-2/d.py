import enum


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    vals = []
    for __ in range(n):
        a = list(map(int, input().split()))
        v = 0
        for i, x in enumerate(a):
            v += (i + 1) * x
        vals.append(v)
    norm = vals[0] if vals[0] == vals[1] else vals[2]
    for i, v in enumerate(vals):
        if v != norm:
            print(i + 1, v - norm)
            break