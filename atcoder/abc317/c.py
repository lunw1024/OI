from itertools import permutations
n, m = map(int, input().split())
e = [[-int(1e9)] * (n + 1) for i in range(n + 1)]
for i in range(m):
    a, b, c = map(int, input().split())
    e[a][b] = c
    e[b][a] = c
ans = 0
for p in permutations(list(range(1, n + 1))):
    k = 0
    for i in range(len(p) - 1):
        x = e[p[i]][p[i+1]]
        if x < 0:
            break
        k += x
    ans = max(ans, k)
print(ans)