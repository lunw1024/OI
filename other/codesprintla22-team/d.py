from math import *
N, T = map(int, input().split())

s = sorted([int(input()) for _ in range(N)])

k = min(s[-int(ceil(N / 4)):]) / 0.9
k = min(k, min(s[-int(ceil(N / 2)):]) / 0.8)
k = min(k, min(s[-int(ceil(N * 3 / 4)):]) / 0.7)

if 0 < k:
    print(int(k))
else:
    print(-1)

