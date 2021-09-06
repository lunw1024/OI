# https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A2
# shoot should've looked at a2 first
import numpy as np
from icecream import ic

N = int(input())

def f(c):
    return ord(c) - ord("A")

def solve(s, dist):
    # ic(dist)
    # ic(list(map(lambda x: ord(x) - ord("A"), s)))
    ans = int(1e9)
    for i in range(26):
        a = sum(dist[j, i] for j in map(lambda x: ord(x) - ord("A"), s))
        ans = min(ans, a)
    return ans if ans < int(1e9) else -1

def floyd(dist):
    n = dist.shape[0]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i, j] = min(dist[i, j], dist[i, k] + dist[k, j])
    return dist

for t in range(1, N + 1):
    s = input()
    K = int(input())
    dist = np.full((26, 26), int(1e9))
    for i in range(26):
        dist[i, i] = 0
    for k in range(K):
        a, b = [ord(c) - ord("A") for c in input()]
        dist[a, b] = 1
    dist = floyd(dist)
    ans = solve(s, dist)
    print(f"Case #{t}: {ans}")

