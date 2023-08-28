import math

T = int(input())

for _ in range(T):
    n = int(input())
    segs = []
    u, v = [], []
    for __ in range(n):
        segs.append([int(x) for x in input().split()])
        u.extend([(segs[-1][2], 'a'), (segs[-1][1], 'r')])
        v.extend([(segs[-1][0], 'l'), (segs[-1][3], 'b')])
    q = int(input())
    qs = []
    for __ in range(q):
        qs.append(int(input()))
        u.append((qs[-1], __, 'q'))
        v.append((qs[-1], __, 'q'))
    l, r = [], []
    for i in u:
